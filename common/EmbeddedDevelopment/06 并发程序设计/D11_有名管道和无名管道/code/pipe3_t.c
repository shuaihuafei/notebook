#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int pfd[2];
    int re;
    char buf[20]={0};
    pid_t pid;
    re = pipe(pfd);
    if(re<0){
        perror("pipe");
        return 0;
    }
    printf("%d,%d\n",pfd[0],pfd[1]);
    pid = fork();
    if(pid<0){
        perror("fork");
        return 0;
    }else if(pid>0){
        close(pfd[0]);
//        close(pfd[1]);
        int j=0;
        while(1){
            j++;
            strcpy(buf,"hhahahahah");
            for(int i=0;i<1000;i++){
                write(pfd[1],buf,strlen(buf));
            }
            printf("write %d times\n",j);
            sleep(1);
        }

    }else{
        close(pfd[1]); 
       // close(pfd[0]);
        sleep(30000);
        exit(0);
       while(1){
            re=read(pfd[0],buf,20);
            if(re>0){
                printf("read pipe=%s\n",buf);
            }else if(re==0){
                printf("re=0\n");
            }
        }
    }


}
