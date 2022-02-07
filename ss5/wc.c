#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void do_wc(const char *path);
static void die(const char *s);

int main(int argc, char* argv[]){

    if(argc < 2){

	fprintf(stderr,"%s: file name not given\n",argv[0]);
	exit(1);
    }

    if(argc > 2){
	
	fprintf(stderr,"warning! too much argument\n");
	exit(1);
    }

    do_wc(argv[1]);
}

#define BUFFER_SIZE 2048

static void do_wc(const char *path){

    int fd;
    unsigned char buf[BUFFER_SIZE];
    int n;
    int num_of_colum = 0;

    fd = open(path,O_RDONLY);

    if(fd < 0) die(path);

    for(;;){

	n = read(fd,buf,sizeof(buf));
	if(n == 0) break ;

	int i;
	for(i = 0; i < sizeof(buf);i++){

	    if(buf[i] == '\n') num_of_colum++;
	}

    }

    printf("number of clum is %d\n",num_of_colum);

    if(close(fd) < 0) die(path);
}

static void die(const char* s){

    perror(s);
    exit(1);
}
