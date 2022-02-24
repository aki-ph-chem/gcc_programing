#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

typedef void (*sighandler_t)(int);

static void trap_signal(int sig, sighandler_t handler);
static void signal_exit(int sig);
static void install_signal_handler(void);

int main(int argc ,char* argv[]){

    pause();
    install_signal_handler();
}

static void trap_signal(int sig, sighandler_t handler){

    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    if(sigaction(sig,&act,NULL) < 0){

	fprintf(stderr,"error in sigaction(2)\n");
	exit(1);
    }
}

static void signal_exit(int sig){

   fprintf(stderr,"ERROR!\n");
   exit(1); 
}

static void install_signal_handler(void){

    trap_signal(SIGINT,signal_exit);
}

