#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){

   pid_t pid;
   pid_t rpid;
   pid = fork();
   int status;
   if(pid<0){
      perror("fork");
      return 0;
   }
   else if(pid == 0){
       sleep(1);
       printf("child will exit\n");
       exit(3);
   }else if(pid >0){
       //rpid = wait(&status);
       waitpid(-1,&status,0);
       printf("Get child status=%x\n",WEXITSTATUS(status));
   }

   while(1){
     sleep(1);
   }

}
