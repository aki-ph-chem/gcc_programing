#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define BUFF_SIZE 1024

int main(void){

    char buf[BUFF_SIZE];

    if(!fgets(buf,sizeof(buf),stdin))exit(1);

    errno = 0;

    if(fputs(buf,stdout) == EOF){

	if(errno != 0)exit(1);
    }

    
}
