#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(){
  pid_t pid;
  pid = fork();
  if(pid<0){
    perror("fork");
    return 0;

  }else if(pid>0){
    exit(0);
//    sleep(100);
  }
  printf("I am a deamon\n");
  printf("sid=%d,pid=%d,pgid=%d\n",getsid(getpid()),getpid(),getpgid(getpid()));

  if(setsid()<0){
    perror("setsid");
    exit(0);
  }  

  printf("after sid=%d,pid=%d,pgid=%d\n",getsid(getpid()),getpid(),getpgid(getpid()));
  
  chdir("/");

  if(umask(0)<0){
    perror("unmask");
    exit(0);
  }
  
  close(0);
  close(1);
  close(2);
  printf("after close \n");  



  sleep(100);

}
