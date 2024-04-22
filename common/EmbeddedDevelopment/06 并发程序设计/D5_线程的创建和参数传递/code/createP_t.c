#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *testThread(void *arg){
    printf("This is a thread test,pid=%d,tid=%lu\n",getpid(),pthread_self());
   // return NULL;
    printf("input arg=%d\n",(int)arg);
    pthread_exit(NULL);
    printf("after pthread exit\n");
}
int main(){
    pthread_t tid;
    int ret;
    int arg = 5;
   
    ret = pthread_create(&tid,NULL,testThread,(void *)arg);

    printf("This is main thread,tid=%lu\n",tid);    
    sleep(1);
}
