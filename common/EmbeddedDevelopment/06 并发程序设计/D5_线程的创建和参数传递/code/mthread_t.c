#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *testThread(void *arg){
    printf("This is a thread test,pid=%d,tid=%lu\n",getpid(),pthread_self());
   // return NULL;
    printf("This is %d thread.\n", (int)arg);
   // pthread_exit(NULL);
    while(1){
        sleep(1);
    }
    printf("after pthread exit\n");
}
int main(){
    pthread_t tid[5];
    int ret;
    int arg = 5;
    int i;
    for(i=0;i<5;i++){   
        ret = pthread_create(&tid[i],NULL,testThread,(void *)i);
     
//        sleep(1);   
        printf("This is main thread,tid=%lu\n",tid[i]);    
    }
    while(1){
        sleep(1);
    }
}
