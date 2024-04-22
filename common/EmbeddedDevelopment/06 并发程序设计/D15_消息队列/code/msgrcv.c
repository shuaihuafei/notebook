#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct{
    long msg_type;
    char buf[128];
}msgT;    

#define MSGLEN  (sizeof(msgT)-sizeof(long))
int main(){
    
    int msgid;
    key_t key;
    msgT msg;
    int ret;
    key = ftok(".",100);
    if(key<0){
        perror("ftok");
        return 0;
    }    
    msgid = msgget(key,IPC_CREAT|0666);
    if(msgid<0){
        perror("msgget");
        return 0;
    }
    int count=0;
    while(1){
        ret = msgrcv(msgid,&msg,MSGLEN,0,0);
        if(ret<0){
            perror("msgrcv");
            return 0;
        } 
        count++;
        if(count>3){
            break;
        }
        printf("receiv msg type=%d,buf=%s\n",(int)msg.msg_type,msg.buf);
    }

    ret = msgctl(msgid,IPC_RMID,NULL);
    if(ret<0){
        perror("msgctl");
        return 0;
    }    


}
