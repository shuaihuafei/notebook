#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char**argv){

   printf("hello world");
   _exit(0);
   printf("after exit");
   return 0;
}
