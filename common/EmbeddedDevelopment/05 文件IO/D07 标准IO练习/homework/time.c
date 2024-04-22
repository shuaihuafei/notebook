/*
 *要求：每隔1秒向文件1.txt写入当前系统时间,行号递增
 */
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    time_t ctime;
    struct tm *ctimestr;
    int linecount = 0;
    char buf[32];
    fp = fopen("1.txt", "a+");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }
    // 获取文件中已有文字的行数
    while (fgets(buf, 32, fp) != NULL)
    {
        // 判断buff的最后一个字符是否为回车，如果是回车说明是读的是一整行
        if (buf[strlen(buf) - 1] == '\n')
        {
            linecount++;
        }
    }
    while (1)
    {
        ctime = time(NULL);
        // printf("ctime=%d\n",(int)ctime);
        ctimestr = localtime(&ctime);
        printf("%04d-%02d-%02d %02d:%02d:%02d\n", ctimestr->tm_year + 1900, ctimestr->tm_mon + 1, ctimestr->tm_mday,
               ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
        fprintf(fp, "%d, %04d-%02d-%02d %02d:%02d:%02d\n", linecount, ctimestr->tm_year + 1900, ctimestr->tm_mon + 1, ctimestr->tm_mday,
                ctimestr->tm_hour, ctimestr->tm_min, ctimestr->tm_sec);
        fflush(fp); // 这一步是为了及时将缓冲区的内容刷新到文件中
        linecount++;
        sleep(1);
    }
    fclose(fp);
}