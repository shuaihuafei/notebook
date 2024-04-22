#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    printf("父进程开始，PID：%d\n", getpid());
    
    // 创建子进程
    pid = fork();
    
    if (pid < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 子进程
        printf("子进程，PID：%d，父进程PID：%d\n", getpid(), getppid());
        
        // 创建孙进程
        pid = fork();
        
        if (pid < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // 孙进程
            printf("孙进程，PID：%d，父进程PID：%d\n", getpid(), getppid());
            
            // 创建重孙进程
            pid = fork();
            
            if (pid < 0) {
                perror("fork error");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // 重孙进程
                printf("重孙进程，PID：%d，父进程PID：%d\n", getpid(), getppid());
                
                // 创建重重孙进程
                pid = fork();
                
                if (pid < 0) {
                    perror("fork error");
                    exit(EXIT_FAILURE);
                } else if (pid == 0) {
                    // 重重孙进程
                    printf("重重孙进程，PID：%d，父进程PID：%d\n", getpid(), getppid());
                }
            }
        }
    }
    while(1){
        sleep(1);
    }
    return 0;
}
