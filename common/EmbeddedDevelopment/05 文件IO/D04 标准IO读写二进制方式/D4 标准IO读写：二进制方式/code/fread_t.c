#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
   FILE *fp;
   char *buff;   
   size_t ret;
   fp=fopen("1.txt","r");
   if(fp==NULL){
      perror("fopen");
      return 0;
   }
   
   buff=(char*)malloc(100);
   if(buff==NULL){
      return 0;

   }

   ret = fread(buff,10,1,fp);
   if(ret==-1){
       perror("fread");
       goto end;
   }
   
   printf("buf=%s\n",buff); 

end:
   free(buff);
   fclose(fp);

}
