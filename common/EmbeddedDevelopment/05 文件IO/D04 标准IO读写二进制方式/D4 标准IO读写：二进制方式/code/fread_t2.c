#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
   char name[16];
   int age;
   char sex[8];
};


int main(int argc,char *argv[]){
   FILE *fp;
   size_t ret;
   
   struct student stu2;

   fp=fopen("1.bin","r");
   if(fp==NULL){
      perror("fopen");
      return 0;
   }
   ret = fread(&stu2,sizeof(stu2),1,fp);
   if(ret ==-1){
      perror("fread");
      goto end;
   }

   printf("name=%s,age=%d,sex=%s\n",stu2.name,stu2.age,stu2.sex);
  


 
end:
   fclose(fp);

}
