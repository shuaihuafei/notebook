#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <linux/posix_types.h>
#include <sys/time.h>


typedef void (*sighandler_t)(int);

sighandler_t oldact;

void handle(int sig){
   if(sig == SIGINT){
        printf("I cath the SIGINT \n");
   }else if (sig==SIGALRM){
       printf("second timer \n");
//       alarm(1);
   }
    //    signal(SIGINT,oldact);
}


int main(){
    struct sigaction act;
    act.sa_handler = handle;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
//    sigaction(SIGINT,&act,NULL);
//    alarm(1);
    struct itimerval timevalue;
    timevalue.it_interval.tv_sec = 1;
    timevalue.it_interval.tv_usec = 0;
    timevalue.it_value.tv_sec = 5;
    timevalue.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL,&timevalue, NULL);
    sigaction(SIGALRM,&act,NULL);
//    oldact = signal(SIGINT,handle);

    while(1){
  //      sleep(1);
    }

} 

