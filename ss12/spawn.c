#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){

    pid_t pid;

    if(argc != 3){

	fprintf(stderr,"Useage,%s <command><arg>\n",argv[0]);
	exit(1);
    }

    pid = fork();
    if(pid < 0){

	fprintf(stderr,"fok(2) failed\n");
	exit(1);
    }

    // child process
    if(pid == 0){

	excel(argv[1],argv[1],argv[2],NULL);
	perror(argv[1]);
	exit(1);
    }else{

	int status;

	waitpid(pid,&status,0);
    }
}
