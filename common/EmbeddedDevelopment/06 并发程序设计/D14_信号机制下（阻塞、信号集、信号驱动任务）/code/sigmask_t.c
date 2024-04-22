#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void handle(int sig){
    
    printf("I get sig=%d\n",sig);

}

int main(){
    
    struct sigaction act;
    act.sa_handler = handle;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT,&act,NULL);
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);

    sigprocmask(SIG_BLOCK,&set,NULL);
    sleep(5);
    sigprocmask(SIG_UNBLOCK,&set,NULL);

    while(1){
        sleep(1);
    }

}
