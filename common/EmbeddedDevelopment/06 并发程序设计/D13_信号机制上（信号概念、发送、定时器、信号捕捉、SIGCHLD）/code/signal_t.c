#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <linux/posix_types.h>

typedef void (*sighandler_t)(int);

sighandler_t oldact;

void handle(int sig){
    printf("I cath the SIGINT \n");
//    signal(SIGINT,oldact);
}

int main(){

    oldact = signal(SIGINT,handle);

    while(1){

        sleep(1);
    }    


}

