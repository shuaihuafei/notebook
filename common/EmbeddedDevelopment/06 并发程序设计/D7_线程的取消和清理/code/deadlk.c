#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

FILE *fp;
void *func2(void *arg){
    pthread_detach(pthread_self());
    printf("This func2 thread\n");
    
    char str[]="I write func2 line\n";
    char c;
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        printf("%d,I got lock2\n",(int)arg);
        sleep(1);
        pthread_mutex_lock(&mutex2);
        printf("%d,I got 2 locks\n",(int)arg);

        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex1);
        sleep(10);

    }

    pthread_exit("func2 exit");

}

void *func(void *arg){
    pthread_detach(pthread_self());
    printf("This is func1 thread\n");
    char str[]="You read func1 thread\n";
    char c;
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        printf("%d,I got lock1\n",(int)arg);
        sleep(1);
        pthread_mutex_lock(&mutex2);
        printf("%d,I got 2 locks\n",(int)arg);

        pthread_mutex_unlock(&mutex2);
        pthread_mutex_unlock(&mutex);
        sleep(10);

    }
    pthread_exit("func1 exit");
}


int main(){
    pthread_t tid,tid2;
    void *retv;
    int i;
    fp = fopen("1.txt","a+");
    if(fp==NULL){
        perror("fopen");
        return 0;
    }


    pthread_create(&tid,NULL,func,1);
    pthread_create(&tid2,NULL,func2,2);

    while(1){    
        sleep(1);
    } 

}
