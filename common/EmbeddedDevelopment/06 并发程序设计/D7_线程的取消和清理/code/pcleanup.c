#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void cleanup(void *arg){
    printf("cleanup,arg=%s\n",(char*)arg);

}
void cleanup2(void* arg){

    printf("cleanup2,arg=%s\n",(char*)arg);
}

void *func(void *arg){
    printf("This is child thread\n");
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    pthread_cleanup_push(cleanup,"abcd");
    pthread_cleanup_push(cleanup2,"efgh");
    //while(1)
    {
        sleep(1);
        
    }
//    pthread_cancel(pthread_self());
    //printf("Should not print\n");
    return "1234";

    while(1){
        printf("sleep\n");
        sleep(1);
    }
    pthread_exit("thread return");
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    sleep(10);
    pthread_exit("thread return");
}


int main(){
    pthread_t tid;
    void *retv;
    int i;
    pthread_create(&tid,NULL,func,NULL);
    sleep(1);
//    pthread_cancel(tid);
    pthread_join(tid,&retv);
    printf("thread ret=%s\n",(char*)retv);
    while(1){    
        sleep(1);
    } 

}
