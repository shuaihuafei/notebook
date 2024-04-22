#include <stdio.h>
#include <unistd.h>
int main(){
    int i=0;
    for(i=0;i<1025;i++)
        printf("a");
    while(1)
        sleep(1);
}