#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){

    void *addr;
    
    addr = mmap(NULL,2048, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if(addr == MAP_FAILED){
        perror("mmap");
        return 0;
    }
    pid_t pid;
    pid = fork();

    if(pid<0){
        perror("fork");
        return 0;
    }
    else if(pid>0){
        memcpy(addr,"1234567890",10);
         
        wait(NULL);
    }else {
        sleep(1);
        printf("read father val=%s\n",(char *)addr);

        

    }
    
    munmap(addr,2048);

}
