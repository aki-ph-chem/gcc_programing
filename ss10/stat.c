#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

static char* filetype(mode_t mode);

int main(int argc, char* argv[]){

    struct stat st;

    if( argc != 2 ){

	fprintf(stderr,"wrong argument\n");
	exit(1);
    }

    if(lstat(argv[1],&st) < 0){

	perror(argv[1]);
	exit(1);
    }

printf("")

}
