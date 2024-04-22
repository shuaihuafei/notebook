#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[16];
    int age;
    char sex[8];
};

int main(int argc, char *argv[])
{
    FILE *fp;
    size_t ret1, ret2;

    struct student stu1;
    struct student stu2;

    fp = fopen("1.bin", "w");
    if (fp == NULL)
    {
        perror("fopen");
        return 0;
    }

    strcpy(stu1.name, "zhangsan");
    stu1.age = 49;
    strcpy(stu1.sex, "male");
    strcpy(stu2.name, "xiaohong");
    stu2.age = 30;
    strcpy(stu2.sex, "female");

    ret1 = fwrite(&stu1, sizeof(stu1), 1, fp);
    ret2 = fwrite(&stu2, sizeof(stu2), 1, fp);
    if ((ret1 == -1) || (ret2 == -1))
    {
        perror("fwrite");
        fclose(fp);
        return 0;
    }
    else
    {
        printf("write struct student success!\n");
    }

    fclose(fp);
    return 0;
}
