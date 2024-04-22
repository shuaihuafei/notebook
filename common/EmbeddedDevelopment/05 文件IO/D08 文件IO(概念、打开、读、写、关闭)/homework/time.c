/*
 *要求：使用文件IO实现“每隔1秒向文件1.txt写入当前系统时间,行号递增”
 */
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd;
    int ret;
    time_t ctime;
    struct tm *ctimestr;
    int linecount = 0;
    char buffer[32];
    char str_time[32];
    int bytesRead;
    fd = open("1.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
    if (fd < 0)
    {
        printf("open file err\n");
        return 0;
    }

    // 获取文件中已有文字的行数
    do
    {
        bytesRead = read(fd, buffer, 32);
        if (bytesRead == -1)
        {
            perror("read");
            close(fd);
            return 0;
        }

        for (int i = 0; i < bytesRead; ++i)
        {
            if (buffer[i] == '\n')
            {
                linecount++;
            }
        }
    } while (bytesRead > 0);

    while (1)
    {
        ctime = time(NULL);
        ctimestr = localtime(&ctime);
        printf("%04d-%02d-%02d %02d:%02d:%02d\n", ctimestr->tm_year + 1900, ctimestr->tm_mon + 1, ctimestr->tm_mday,
               ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
        sprintf(str_time, "%d, %04d-%02d-%02d %02d:%02d:%02d\n", linecount, ctimestr->tm_year + 1900, ctimestr->tm_mon + 1, ctimestr->tm_mday,
                ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
        // 将buf中的内容写入到fd中
        ret = write(fd, str_time, strlen(str_time));
        if (ret < 0)
        {
            close(fd);
            return 0;
        }
        linecount++;
        sleep(1);
    }
    close(fd);
}