#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void){

    pid_t pid;

    int fds[2];
    pipe(fds);

    pid = fork();
    if(pid < 0){

	fprintf(stderr,"fork(2) failed\n");
	exit(1);
    }

    //child process
    if(pid == 0){

	close(fds[1]);
	
	char* command = "/usr/bin/sed -e s/h/H";
	execl(command,command,NULL);
	perror(command);
	exit(99);
    //parent process
    }else{

	close(fds[0]);
	
	char* buf = "hi!\n";
	if(write(fds[1],buf,sizeof(buf))){

	    fprintf(stderr,"Errot in  write(2)\n");
	    exit(1);
	}

	int status;

	waitpid(pid,&status,0);
	printf("chidl (PID=%d) failed;",pid);

	if(WIFEXITED(status))
	    printf("exit, status%d\n",WEXITSTATUS(status));

	else if(WIFSIGNALED(status))
	    printf("signal, sig%d\n",WTERMSIG(status));
	else 
	    printf("abnormal exit\n");
	exit(0);
    }


}
