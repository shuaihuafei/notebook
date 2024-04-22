#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


pthread_rwlock_t rwlock;

FILE *fp;
void * read_func(void *arg){
    pthread_detach(pthread_self());
    printf("read thread\n");
    char buf[32]={0};
    while(1){
        //rewind(fp);
        pthread_rwlock_rdlock(&rwlock);
        while(fgets(buf,32,fp)!=NULL){
            printf("%d,rd=%s\n",(int)arg,buf);
            usleep(1000);
        }
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }

}



void *func2(void *arg){
    pthread_detach(pthread_self());
    printf("This func2 thread\n");
    
    char str[]="I write func2 line\n";
    char c;
    int i=0;
    while(1){
        pthread_rwlock_wrlock(&rwlock);
        while(i<strlen(str))
        {
            c = str[i];
            fputc(c,fp);
            usleep(1);
            i++;
        }
        pthread_rwlock_unlock(&rwlock);
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
        pthread_rwlock_wrlock(&rwlock);
        while(i<strlen(str))
        {
            c = str[i];
            fputc(c,fp);
            i++;
            usleep(1);
        }
        pthread_rwlock_unlock(&rwlock);
        i=0;
        usleep(1);

    }
    pthread_exit("func1 exit");
}


int main(){
    pthread_t tid1,tid2,tid3,tid4;
    void *retv;
    int i;
    fp = fopen("1.txt","a+");
    if(fp==NULL){
        perror("fopen");
        return 0;
    }
    pthread_rwlock_init(&rwlock,NULL);
    pthread_create(&tid1,NULL,read_func,1);
    pthread_create(&tid2,NULL,read_func,2);
    pthread_create(&tid3,NULL,func,NULL);
    pthread_create(&tid4,NULL,func2,NULL);
    while(1){    
        sleep(1);
    } 

}
