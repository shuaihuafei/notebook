#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


FILE *fp;
void *func2(void *arg){
    pthread_detach(pthread_self());
    printf("This func2 thread\n");
    
    char str[]="I write func2 line\n";
    char c;
    int i=0;
    while(1){
        pthread_mutex_lock(&mutex);
        while(i<strlen(str))
        {
            c = str[i];
            fputc(c,fp);
            usleep(1);
            i++;
        }
        pthread_mutex_unlock(&mutex);
        i=0;
        usleep(1);

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
        while(i<strlen(str))
        {
            c = str[i];
            fputc(c,fp);
            i++;
            usleep(1);
        }
        pthread_mutex_unlock(&mutex);
        i=0;
        usleep(1);

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


    pthread_create(&tid,NULL,func,NULL);
    pthread_create(&tid2,NULL,func2,NULL);
    while(1){    
        sleep(1);
    } 

}
