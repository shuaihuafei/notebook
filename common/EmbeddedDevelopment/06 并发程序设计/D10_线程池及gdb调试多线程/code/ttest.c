#include <pthread.h>
#include <stdio.h>

void *testThread(void *arg){
    char *threadName = (char*)arg;
    printf("Current running %s\n",threadName);

    printf("aaaaaaaa\n");
    printf("bbbbbbbb\n");

    pthread_exit(0);

}


int main(){
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,testThread,"thread1");
    pthread_create(&tid2,NULL,testThread,"thread2");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);


}
