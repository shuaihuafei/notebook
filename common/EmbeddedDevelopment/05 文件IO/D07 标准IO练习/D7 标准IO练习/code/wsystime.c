#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char *argv[]){
     FILE *fp;
     time_t ctime;
     struct tm *ctimestr;
     int linecount = 0; 
     char buf[32];
     fp=fopen("test.txt","a+");
     if(fp==NULL){
         perror("fopen");
         return 0;

     }
     //calculate test.txt  line    

     while(fgets(buf,32,fp)!=NULL){
         
          if(buf[strlen(buf)-1] =='\n'){
               linecount++;
          }


    } 


 
     while(1){
         ctime = time(NULL);
         //printf("ctime=%d\n",(int)ctime);
         ctimestr = localtime(&ctime);
         printf("%04d-%02d-%02d %02d:%02d:%02d\n",ctimestr->tm_year+1900,ctimestr->tm_mon+1,ctimestr->tm_mday,
                                     ctimestr->tm_hour,ctimestr->tm_min,ctimestr->tm_sec);
         fprintf(fp,"%d, %04d-%02d-%02d %02d:%02d:%02d\n",linecount,ctimestr->tm_year+1900,ctimestr->tm_mon+1,ctimestr->tm_mday,
                                     ctimestr->tm_hour,ctimestr->tm_min,ctimestr->tm_sec);
         fflush(fp);
         linecount++;
         sleep(1);
     }

     fclose(fp);

}


