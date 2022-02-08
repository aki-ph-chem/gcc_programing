#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

int main(void){

    char buf[] = "Hello World\n";
    errno = 0;

    if(fputs(buf,stdout) == EOF){

	if(errno != 0)exit(1);
    }
}
