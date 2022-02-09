#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define BUFF_SIZE 2048

int main(int argc, char *argv[]){
    
    errno = 0;
    int i;

    if(argc < 2){

	fprintf(stderr,"%s:file name not given\n",argv[0]);
	exit(1);
    }

    for(i = 1; i < argc; i++){

	FILE *f;
	unsigned char buf[BUFF_SIZE];
	size_t nmemb = 1;

	f = fopen(argv[i],"r");
	if(!f){

	    perror(argv[i]);
	    exit(1);
	}

	for(;;){

	    if(fread(buf, sizeof(buf),nmemb,f) < nmemb){

		if(ferror(f)){

		    exit(1);

		}else{

		    break;
		}
	    }

	    if(fwrite(buf,sizeof(buf),nmemb,stdout) < nmemb){

		if(errno != 0)exit(1);
	    }
	}

	fclose(f);
    }
}

