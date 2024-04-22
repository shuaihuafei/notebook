#include <stdio.h>
#include <unistd.h>

int main(){

   printf("before exec\n");
   if(execlp("ls","ls","-a","-l","./",NULL)<0){
	perror("execl");
   }


}
