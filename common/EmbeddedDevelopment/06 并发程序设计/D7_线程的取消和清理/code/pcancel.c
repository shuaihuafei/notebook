#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *func(void *arg){
    printf("This is child thread\n");
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);    
//    while(1)
    {
        sleep(5);
        pthread_testcancel();
    }
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    while(1){
        sleep(1);
    }


    pthread_exit("thread return");
}


int main(){
    pthread_t tid;
    void *retv;
    int i;
    pthread_create(&tid,NULL,func,NULL);
    sleep(1);
    pthread_cancel(tid);
    pthread_join(tid,&retv);
//    printf("thread ret=%s\n",(char*)retv);
    while(1){    
        sleep(1);
    } 

}
