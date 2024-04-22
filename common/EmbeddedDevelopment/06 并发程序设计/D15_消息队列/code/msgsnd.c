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
    key_t key;
    int msgid;
    int ret;
    msgT msg;
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

    msg.msg_type = 1;
    strcpy(msg.buf,"this msg type 1");
    ret = msgsnd(msgid,&msg,MSGLEN,0);
    if(ret<0){
        perror("msgsnd");
        return 0;
    }    

    msg.msg_type = 2;
    strcpy(msg.buf,"this msg type 2");
    ret = msgsnd(msgid,&msg,MSGLEN,0);
    if(ret<0){
        perror("msgsnd");
        return 0;
    }
    msg.msg_type = 3;
    strcpy(msg.buf,"this msg type 3");
    ret = msgsnd(msgid,&msg,MSGLEN,0);
    if(ret<0){
        perror("msgsnd");
        return 0;
    }
    msg.msg_type = 4;
    strcpy(msg.buf,"this msg type 4");
    ret = msgsnd(msgid,&msg,MSGLEN,0);
    if(ret<0){
        perror("msgsnd");
        return 0;
    }
    msg.msg_type = 5;
    strcpy(msg.buf,"this msg type 5");
    ret = msgsnd(msgid,&msg,MSGLEN,0);
    if(ret<0){
        perror("msgsnd");
        return 0;
    }








}
