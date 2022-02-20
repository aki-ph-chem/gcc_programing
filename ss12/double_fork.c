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

	fprintf(stderr,"fork(2) failed\n");
	exit(1);
    }

    // child process
    if(pid == 0){

	pid_t pid_at_gchild;

	pid_at_gchild = fork();
	if(pid_at_gchild < 0){

	    fprintf(stderr,"fork(2) failed\n");
	    exit(1);
	}

	// grand child process
	if(pid_at_gchild == 0){

	    execl(argv[1],argv[2],NULL);
	    perror(argv[1]);
	}else if(pid_at_gchild != 0){

	    exit(1);
	}    


    }

}
