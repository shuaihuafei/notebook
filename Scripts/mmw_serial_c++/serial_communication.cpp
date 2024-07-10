#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <chrono>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <iomanip>

std::vector<uint8_t> data_queue;
std::atomic<bool> running(true); // 线程运行标志
boost::asio::io_service io;
boost::asio::serial_port serial(io);

class SerialWrapper
{
public:
    SerialWrapper(const std::string &port, unsigned int baudrate, boost::asio::serial_port_base::character_size bytesize,
                  boost::asio::serial_port_base::parity parity, boost::asio::serial_port_base::stop_bits stopbits)
        : port(port), baudrate(baudrate), bytesize(bytesize), parity(parity), stopbits(stopbits) {}

    bool open_serial()
    {
        try
        {
            serial.open(port);
            serial.set_option(boost::asio::serial_port_base::baud_rate(baudrate));
            serial.set_option(bytesize);
            serial.set_option(parity);
            serial.set_option(stopbits);
            std::cout << "Serial port configured: BaudRate = " << baudrate
                      << ", StopBits = " << stop_bits_to_string(stopbits)
                      << ", Parity = " << parity_to_string(parity) << std::endl;
            return true;
        }
        catch (boost::system::system_error &e)
        {
            std::cerr << "Error opening serial port: " << e.what() << std::endl;
            return false;
        }
    }

    void close()
    {
        if (serial.is_open())
        {
            serial.close();
            std::cout << "Serial port closed" << std::endl;
        }
    }

    void write_data(const std::vector<uint8_t> &data)
    {
        while (running)
        {
            try
            {
                boost::asio::write(serial, boost::asio::buffer(data));
                std::cout << "Data written: ";
                for (auto byte : data)
                    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
                std::cout << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 模拟间隔发送
            }
            catch (boost::system::system_error &e)
            {
                if (!running)
                    break;
                std::cerr << "Error writing to port: " << e.what() << std::endl;
            }
        }
    }

    void read_data()
    {
        while (running)
        {
            try
            {
                uint8_t buf[256];
                boost::system::error_code ec;
                size_t len = serial.read_some(boost::asio::buffer(buf), ec);
                if (ec)
                {
                    if (!running)
                        break;
                    std::cerr << "Error reading from port: " << ec.message() << std::endl;
                }
                else if (len > 0)
                {
                    process_received_data(buf, len);
                }
            }
            catch (boost::system::system_error &e)
            {
                if (!running)
                    break;
                std::cerr << "Error reading from port: " << e.what() << std::endl;
            }
        }
    }

    void process_received_data(uint8_t *data, size_t length)
    {
        data_queue.insert(data_queue.end(), data, data + length);
        std::cout << "Current data_queue: ";
        for (const auto &byte : data_queue)
        {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)byte << " ";
        }
        std::cout << std::endl;

        while (data_queue.size() >= 7)
        {
            if (data_queue[0] == 0x01 && data_queue[1] == 0x03 && data_queue[2] == 0x02)
            {
                std::vector<uint8_t> valid_data(data_queue.begin(), data_queue.begin() + 7);
                std::cout << "Valid data found: ";
                for (auto byte : valid_data)
                    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
                std::cout << std::endl;

                unsigned int combined_value = (valid_data[3] << 8) | valid_data[4];
                std::cout << "Measure Distance is: " << std::dec << combined_value << " cm" << std::endl;

                data_queue.erase(data_queue.begin(), data_queue.begin() + 7);
            }
            else
            {
                data_queue.erase(data_queue.begin());
            }
        }
    }

private:
    std::string port;
    unsigned int baudrate;
    boost::asio::serial_port_base::character_size bytesize;
    boost::asio::serial_port_base::parity parity;
    boost::asio::serial_port_base::stop_bits stopbits;

    std::string stop_bits_to_string(boost::asio::serial_port_base::stop_bits stopbits)
    {
        switch (stopbits.value())
        {
        case boost::asio::serial_port_base::stop_bits::one:
            return "1";
        case boost::asio::serial_port_base::stop_bits::onepointfive:
            return "1.5";
        case boost::asio::serial_port_base::stop_bits::two:
            return "2";
        default:
            return "unknown";
        }
    }

    std::string parity_to_string(boost::asio::serial_port_base::parity parity)
    {
        switch (parity.value())
        {
        case boost::asio::serial_port_base::parity::none:
            return "none";
        case boost::asio::serial_port_base::parity::odd:
            return "odd";
        case boost::asio::serial_port_base::parity::even:
            return "even";
        default:
            return "unknown";
        }
    }
};

int main()
{
    std::cout << " +----------------------------------+" << std::endl;
    std::cout << " |        Serial Port Write         |" << std::endl;
    std::cout << " +----------------------------------+" << std::endl;

    std::vector<uint8_t> write_buffer = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};

    SerialWrapper serial_wrapper("/dev/ttyUSB0", 115200, boost::asio::serial_port_base::character_size(8),
                                 boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
                                 boost::asio::serial_port_base::stop_bits(boost::asio::serial_port_base::stop_bits::one));

    if (serial_wrapper.open_serial())
    {
        std::thread send_thread(&SerialWrapper::write_data, &serial_wrapper, std::ref(write_buffer));
        std::thread receive_thread(&SerialWrapper::read_data, &serial_wrapper);

        send_thread.join();    // 等待发送线程结束
        receive_thread.join(); // 等待接收线程结束
    }

    std::cout << "\nSerial communication ended" << std::endl;
    return 0;
}
