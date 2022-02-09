#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int main(void){

    errno = 0;

    char string[] = "Hello\n";

    if(fwrite(string,sizeof(string),1,stdout) != 1){

	if(errno != 0)exit(1);
    }

}
