#include <stdio.h>

int main(int argc,char *argv[]){
    
   FILE *fp;
   fp=fopen("1.txt","w");
   if(fp==NULL){
      perror("fopen");
      return 0;
   }

   fwrite("abcdef",6,1,fp);
   printf("current fp=%d\n",(int)ftell(fp));
//   fseek(fp,3,SEEK_SET);
   rewind(fp);
   printf("After rewind fp=%d\n",(int)ftell(fp));
   fwrite("vvv",3,1,fp);




}
