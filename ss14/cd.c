#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    if(argc < 2){

	fprintf(stderr,"No argment\n");
	exit(1);
    }

    if(chdir(argv[1]) < 0){

	fprintf(stderr,"Error in chdir(2)\n");
	exit(1);
    }

}
