#include<stdio.h>

int main(void){

    int fd_of_stdin;
    int fd_of_stdout;
    int fd_of_stderr;

    fd_of_stdin  = fileno(stdin);
    fd_of_stdout = fileno(stdout);
    fd_of_stderr = fileno(stderr);

    printf("fd_of_stdin is %d\n",fd_of_stdin);
    printf("fd_of_stdout is %d\n",fd_of_stdout);
    printf("fd_of_stderr is %d\n",fd_of_stderr);


}
