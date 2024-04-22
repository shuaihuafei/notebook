#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int i;
    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return 0;
        }
        else if (pid == 0)
        {
            printf("child process\n");
            sleep(2);
            break;
        }
        else
        {
            printf("Father process\n");
            sleep(2);
        }
    }

    sleep(20);
}
