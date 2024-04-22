#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc,char *argv[]){
    FILE *fp;
    int fpret;
    fp = fopen("1.txt","r");
    if(fp==NULL){
        //printf("Open file Failed\n");
        perror("fopen");
        printf("fopen:%s\n",strerror(errno));
                

    }else{
	printf("Open file success\n");
       // perror("open");
       fpret = fclose(fp);
       if(fpret==0){
            printf("file close sucess\n");
       }else{
            perror("fclose");
       }
    }
    

}
