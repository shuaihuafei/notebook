#include <stdio.h>
int main(){
   int a[5][4], (*p)[4]=a;
   printf("%d\n",*(p+2)+3);


}
