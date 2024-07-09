#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>
#include <deque>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <cerrno>

std::deque<unsigned char> data_queue;

class Serial
{
public:
    Serial(const std::string &port, int baudrate, int bytesize, const std::string &parity, int stopbits, const std::string &flowcontrol)
        : port(port), baudrate(baudrate), bytesize(bytesize), parity(parity), stopbits(stopbits), flowcontrol(flowcontrol), fd(-1) {}

    bool openSerial()
    {
        fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
        if (fd == -1)
        {
            std::cerr << "Error opening serial port: " << strerror(errno) << std::endl;
            return false;
        }

        configureSerialPort();
        return true;
    }

    void closeSerial()
    {
        if (fd != -1)
        {
            close(fd);
            fd = -1;
        }
    }

    int getFd() const
    {
        return fd;
    }

    ~Serial()
    {
        closeSerial();
    }

private:
    void configureSerialPort()
    {
        struct termios SerialPortSettings;

        if (tcgetattr(fd, &SerialPortSettings) != 0)
        {
            std::cerr << "ERROR! in Getting attributes: " << strerror(errno) << std::endl;
            return;
        }

        cfsetispeed(&SerialPortSettings, getBaudRate(baudrate));
        cfsetospeed(&SerialPortSettings, getBaudRate(baudrate));

        SerialPortSettings.c_cflag &= ~CSIZE;
        SerialPortSettings.c_cflag |= getByteSize(bytesize);

        if (parity == "None")
        {
            SerialPortSettings.c_cflag &= ~PARENB;
        }
        else if (parity == "Odd")
        {
            SerialPortSettings.c_cflag |= PARENB;
            SerialPortSettings.c_cflag |= PARODD;
        }
        else if (parity == "Even")
        {
            SerialPortSettings.c_cflag |= PARENB;
            SerialPortSettings.c_cflag &= ~PARODD;
        }

        if (stopbits == 1)
        {
            SerialPortSettings.c_cflag &= ~CSTOPB;
        }
        else if (stopbits == 2)
        {
            SerialPortSettings.c_cflag |= CSTOPB;
        }

        if (flowcontrol == "None")
        {
            SerialPortSettings.c_cflag &= ~CRTSCTS;
        }
        else if (flowcontrol == "RTS/CTS")
        {
            SerialPortSettings.c_cflag |= CRTSCTS;
        }

        SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY | ICANON | ECHO | ECHOE | ISIG);
        SerialPortSettings.c_oflag &= ~OPOST;

        SerialPortSettings.c_cc[VMIN] = 0;
        SerialPortSettings.c_cc[VTIME] = 10;

        tcflush(fd, TCIFLUSH);
        tcflush(fd, TCOFLUSH);

        if ((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0)
        {
            std::cerr << "ERROR! in Setting attributes: " << strerror(errno) << std::endl;
        }
        else
        {
            std::cout << "Serial port configured: BaudRate = " << baudrate
                      << " StopBits = " << stopbits
                      << " Parity = " << parity << std::endl;
        }
    }

    speed_t getBaudRate(int baudrate)
    {
        switch (baudrate)
        {
        case 115200:
            return B115200;
        case 57600:
            return B57600;
        case 38400:
            return B38400;
        case 19200:
            return B19200;
        case 9600:
            return B9600;
        case 4800:
            return B4800;
        case 2400:
            return B2400;
        case 1200:
            return B1200;
        default:
            return B9600;
        }
    }

    tcflag_t getByteSize(int bytesize)
    {
        switch (bytesize)
        {
        case 5:
            return CS5;
        case 6:
            return CS6;
        case 7:
            return CS7;
        case 8:
            return CS8;
        default:
            return CS8;
        }
    }

    std::string port;
    int baudrate;
    int bytesize;
    std::string parity;
    int stopbits;
    std::string flowcontrol;
    int fd;
};

void send_data(int fd, const unsigned char *write_buffer, size_t buffer_size)
{
    while (true)
    {
        int bytes_written = write(fd, write_buffer, buffer_size);
        if (bytes_written < 0)
        {
            std::cerr << "Error writing to ttyUSB0: " << strerror(errno) << std::endl;
            return;
        }

        // std::cout << "Data written to ttyUSB0: ";
        // for (size_t i = 0; i < buffer_size; ++i)
        // {
        //     std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)write_buffer[i] << " ";
        // }
        // std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void receive_and_check_data(int fd)
{
    while (true)
    {
        std::vector<unsigned char> read_buffer(256);
        fd_set read_fds;
        struct timeval timeout;

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);

        int select_result = select(fd + 1, &read_fds, NULL, NULL, &timeout);
        if (select_result == -1)
        {
            std::cerr << "Error in select(): " << strerror(errno) << std::endl;
            return;
        }
        else if (select_result > 0 && FD_ISSET(fd, &read_fds))
        {
            int bytes_available;
            ioctl(fd, FIONREAD, &bytes_available);
            if (bytes_available > 0)
            {
                read_buffer.resize(bytes_available);
                int bytes_read = read(fd, read_buffer.data(), bytes_available);
                if (bytes_read < 0)
                {
                    if (errno == EAGAIN || errno == EWOULDBLOCK)
                    {
                        std::cerr << "Resource temporarily unavailable, retrying..." << std::endl;
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        continue;
                    }
                    else
                    {
                        std::cerr << "Error reading from ttyUSB0: " << strerror(errno) << std::endl;
                        return;
                    }
                }
                else
                {
                    data_queue.insert(data_queue.end(), read_buffer.begin(), read_buffer.end());
                    std::cout << "Current data_queue: ";
                    for (const auto &byte : data_queue)
                    {
                        std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)byte << " ";
                    }
                    std::cout << std::endl;
                }
            }
        }

        while (data_queue.size() >= 7)
        {
            if (data_queue[0] == 0x01 && data_queue[1] == 0x03 && data_queue[2] == 0x02)
            {
                std::vector<unsigned char> valid_data(data_queue.begin(), data_queue.begin() + 7);
                std::cout << "Valid data found: ";
                for (const auto &byte : valid_data)
                {
                    std::cout << std::hex << std::setw(2) << std::setfill('0') << (unsigned int)byte << " ";
                }
                std::cout << std::endl;

                unsigned int combined_value = (valid_data[3] << 8) | valid_data[4];
                std::cout << "Measure Distance is: " << std::dec << combined_value << " cm" << std::endl;

                data_queue.erase(data_queue.begin(), data_queue.begin() + 7);
            }
            else
            {
                data_queue.pop_front();
            }
        }
    }
}

int main()
{
    unsigned char write_buffer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};

    std::cout << "\n +----------------------------------+" << std::endl;
    std::cout << " |        Serial Port Write         |" << std::endl;
    std::cout << " +----------------------------------+" << std::endl;

    Serial serial("/dev/ttyUSB0", 115200, 8, "None", 1, "None");
    if (!serial.openSerial())
    {
        return -1;
    }

    std::thread send_thread(send_data, serial.getFd(), write_buffer, sizeof(write_buffer));
    std::thread receive_check_thread(receive_and_check_data, serial.getFd());

    send_thread.join();
    receive_check_thread.join();

    serial.closeSerial();

    std::cout << "\n +----------------------------------+" << std::endl;
    return 0;
}
