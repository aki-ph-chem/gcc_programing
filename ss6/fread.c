#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define BUFF_SIZE 1024 

int main(void){

    errno = 0;

    char buf[BUFF_SIZE];

    if(fread(buf,3,1,stdin) != 1){

	if(ferror(stdin))exit(1);
    }

    fwrite(buf,sizeof(buf),1,stdout);
    if(errno == 0)exit(1);
}
