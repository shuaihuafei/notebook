#include <stdio.h>
#include <errno.h>
#include <string.h>

#define TXTFILE "1.txt"
int main(int argc,char *argv[]){
    FILE *fp;
    int fpret;
    fp = fopen(TXTFILE,"r");
    if(fp==NULL){
        perror("fopen");
        printf("fopen: %s\n",strerror(errno));
    }else{
	    printf("Open file success\n");
        fpret = fclose(fp);
        if(fpret==0){
            printf("file close sucess\n");
        }else{
            perror("fclose");
        }
    }
}
