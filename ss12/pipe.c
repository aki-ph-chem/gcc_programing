#include<stdio.h>
#include<stdlib.h>

int main(void){

    FILE* sed = popen("/usr/bin/sed -e s/h/H/","w");
    if(!sed){

	fprintf(stderr,"cannot open sed\n");
	exit(1);
    }

    fprintf(sed,"hi!\n");

    pclose(sed);
}
