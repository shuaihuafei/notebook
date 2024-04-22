#include <stdio.h>

int main(int argc,char *argv[]){
    FILE *fp;
    int retn;
    fp = fopen("1.txt","w");
    if(fp==NULL){
	    perror("fopen");
        return 0;
    }

    retn = fputs("This is test.\n",fp);
    if(retn==-1){
	    perror("fputs");
    }
    fclose(fp);
}
