#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define BUFF_SIZE 1024

int main(void){

    errno = 0;

    char buf[BUFF_SIZE];

    fread(buf,2,1,stdin);

    fwrite(buf,2,1,stdout);
    if(errno == 0)exit(1);
}
