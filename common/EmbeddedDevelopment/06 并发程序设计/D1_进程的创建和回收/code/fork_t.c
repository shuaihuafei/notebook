#include <stdio.h>
#include <unistd.h>

int main(int argc,char **argv){
    
    pid_t pid;
    printf("before fork\n");
    pid = fork();
    if(pid>0){
       printf("This is father process\n");
       printf("pid=%d\n",(int)pid);
       printf("father after fork\n");
       while(1){
         sleep(1);
         printf("father sleep\n");
       }
   }else if(pid==0){
       printf("This is child process\n");
       printf("pid=%d\n",(int)pid);
       printf("child after fork\n");
       while(1){
          sleep(1);
          printf("child sleep\n");
       }
    }else if(pid<0){
       perror("fork");
       return 0;
    }
   // printf("pid=%d\n",(int)pid);
  //  printf("after fork\n");
  

}
