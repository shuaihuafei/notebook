#include "stdio.h"

int main(int argc,char *argv[]){

    char buf[100]={0};
    int year=2021;
    int month= 10;
    int day=1;

    int syear;
    int smonth;
    int sday;

    sprintf(buf,"%d-%d-%d",year,month,day);
   
    printf("%s\n",buf);

    sscanf(buf,"%d-%d-%d",&syear,&smonth,&sday);
    printf("%d,%d,%d\n",syear,smonth,sday);

}
