/*
 * 要求：遍历一个文件夹下所有文件，并打印文件大小和日期
 */
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
    DIR *dp;
    struct dirent *dt;
    char *path = "/home/";
    dp = opendir(path);
    if (dp == NULL)
    {
        perror("opendir");
        return 0;
    }
    while ((dt = readdir(dp)) != NULL)
    {
        // printf("%s\n", dt->d_name);
        struct stat buf;
        int ret;
        // 此处为字符串拼接
        char *path_filename = (char *)malloc(strlen(path) + strlen(dt->d_name));
        sprintf(path_filename, "%s%s", path, dt->d_name);
        ret = stat(path_filename, &buf);
        if (ret < 0)
        {
            perror("stat");
            return 0;
        }

        printf(" %d", (int)buf.st_size);

        struct tm *t;
        t = localtime(&buf.st_ctime);
        printf(" %d-%d-%d %d:%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min);

        printf(" %s\n", dt->d_name);
    }
    closedir(dp);
}
