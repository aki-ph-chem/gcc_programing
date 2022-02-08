#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

static void read_by_buf(int fd);

#define BUFF_SIZE 2 

int fd;
unsigned char buf[BUFF_SIZE];
int n;

int main(int argc, char* argv[]){

    if(argc < 2){

	fprintf(stderr,"%s: file name not given\n",argv[0]);
	exit(1);
    }

    if(argc > 2){

	fprintf(stderr,"too much argument\n");
	exit(1);
    }


    const char* path;
    path = argv[1];
    
    fd = open(path, O_RDONLY);
    if(fd < 0) exit(1);
    
    lseek(fd,2,SEEK_SET);
    read_by_buf(fd);
    
    if(close(fd) < 0)exit(1);
}


static void read_by_buf(int fd){
    
    n = read(fd,buf,sizeof(buf));

    if(n < 0)exit(1);

    if(write(STDOUT_FILENO,buf,n) < 0)exit(1);
}

