#include <iostream>
#include <thread>
#include <vector>
#include <deque>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <sys/select.h>
#include <sys/ioctl.h>

std::deque<unsigned char> data_queue;

void configure_serial_port(int fd)
{
    struct termios SerialPortSettings;

    tcgetattr(fd, &SerialPortSettings);

    // 设置波特率
    cfsetispeed(&SerialPortSettings, B115200);
    cfsetospeed(&SerialPortSettings, B115200);

    // 设置没有校验
    SerialPortSettings.c_cflag &= ~PARENB;

    // 停止位 = 1
    SerialPortSettings.c_cflag &= ~CSTOPB;
    SerialPortSettings.c_cflag &= ~CSIZE;

    // 设置数据位 = 8
    SerialPortSettings.c_cflag |= CS8;

    SerialPortSettings.c_cflag &= ~CRTSCTS;
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;

    // 关闭软件流动控制
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);

    // 设置操作模式
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    SerialPortSettings.c_oflag &= ~OPOST;

    if ((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0)
    {
        std::cerr << "ERROR! in Setting attributes: " << strerror(errno) << std::endl;
    }
    else
    {
        std::cout << "BaudRate = 115200 \nStopBits = 1 \nParity = none" << std::endl;
    }
}

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

        std::cout << "Data written to ttyUSB0: ";
        for (size_t i = 0; i < buffer_size; ++i)
        {
            std::cout << std::hex << (unsigned int)write_buffer[i] << " ";
        }
        std::cout << std::endl;
        // std::cout << bytes_written << " Bytes written to ttyUSB0" << std::endl;

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
                        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 等待100毫秒后重试
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
                    // std::cout << bytes_read << " Bytes read from ttyUSB0" << std::endl;
                    data_queue.insert(data_queue.end(), read_buffer.begin(), read_buffer.end());
                    // 打印 data_queue 中的所有数据
                    std::cout << "Current data_queue: ";
                    for (const auto &byte : data_queue)
                    {
                        std::cout << std::hex << (unsigned int)byte << " ";
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
                    std::cout << std::hex << (unsigned int)byte << " ";
                }
                std::cout << std::endl;
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
    int fd;
    unsigned char write_buffer[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};

    std::cout << "\n +----------------------------------+" << std::endl;
    std::cout << " |        Serial Port Write         |" << std::endl;
    std::cout << " +----------------------------------+" << std::endl;

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);

    if (fd == -1)
    {
        std::cerr << "Error! in Opening ttyUSB0: " << strerror(errno) << std::endl;
        return -1;
    }
    else
    {
        std::cout << "ttyUSB0 Opened Successfully" << std::endl;
    }

    configure_serial_port(fd);

    std::thread send_thread(send_data, fd, write_buffer, sizeof(write_buffer));
    std::thread receive_check_thread(receive_and_check_data, fd);

    send_thread.join();
    receive_check_thread.join();

    close(fd);
    std::cout << "\n +----------------------------------+" << std::endl;
    return 0;
}
