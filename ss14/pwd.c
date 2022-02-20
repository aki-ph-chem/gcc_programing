#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#define INT_BUFSIZE 1024

char* my_getcwd(void);

int main(void){

    char* current_directory = my_getcwd();
    printf("%s\n",current_directory);
    return 0;
}

char* my_getcwd(void){

    char *buf,*tmp;
    size_t size = INT_BUFSIZE;

    buf = malloc(size);
    for(;;){

	errno = 0;
	if(getcwd(buf,size))
	    return buf;
	if(errno != ERANGE) break;
	size *= 2;
	tmp =realloc(buf,size);
	if(!tmp) break;
	buf = tmp;
    }

    free(buf);
    return NULL;
}
