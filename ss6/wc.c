#include<stdio.h>
#include<stdlib.h>


int main(int argc,char* argv[]){

    if(argc < 2){

	fprintf(stderr,"%s: file name not given\n",argv[0]);
	exit(1);
    }

    if(argc > 2){

	fprintf(stderr,"too much argument\n");
	exit(1);
    }


    FILE *f;
    int c;  
    int num_of_colum = 0;

    f = fopen(argv[1],"r");
    if(!f){

	perror(argv[1]);
	exit(1);
    }

    while((c = fgetc(f)) != EOF){

	if(c == '\n'){

	    num_of_colum++;
	}

    }

    fclose(f);

    printf("number of colum is %d \n",num_of_colum);

}



