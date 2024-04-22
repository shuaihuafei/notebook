#include <stdio.h>
#include <unistd.h>

int main(){
   char *agv[] = {"ls","-a","-l","./",NULL};

   if(execv("/bin/ls",agv)<0){
	perror("execv");
   }


}
