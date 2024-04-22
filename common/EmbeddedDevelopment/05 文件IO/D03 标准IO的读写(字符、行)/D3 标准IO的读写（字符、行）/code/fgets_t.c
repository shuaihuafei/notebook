#include <stdio.h>

int main(int argc,char *argv[]){
    FILE *fp;
    char *ret;
    int retn;
    char buff[100];
    fp = fopen("1.txt","a+");
    if(fp==NULL){
	    perror("fopen");
        return 0;

    }


    // ret = fgets(buff,5,fp);
    // if(ret==NULL){
	//     perror("fgets");
    //     fclose(fp);
    //     return 0;
    // }
    // printf("buff=%s\n",buff);


    retn = fputs("hello world",fp);
    if(retn==-1){
	    perror("fputs");
    }
    printf("hahaha\n");
    
    fclose(fp);

}
