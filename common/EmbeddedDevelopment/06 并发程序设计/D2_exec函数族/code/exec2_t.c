#include <stdio.h>
#include <unistd.h>

int main(){
   pid_t pid;
   printf("before exec\n");
   pid = fork();
   if(pid==0){
   	if(execl("/bin/ls","-a","-l","./",NULL)<0){
		perror("execl");
   	}
   }
   	printf("after execl\n");
  

}
