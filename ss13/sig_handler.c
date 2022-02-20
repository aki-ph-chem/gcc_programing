#include<signal.h>

typedef void (*singhandler_t)(int);

sighandler_t trap_signal(int sig, singhandler_t handler){

    struct sigaction act, old;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    sa.sa_flags = SA_RESTART;
    if(sigaction(sig,&act,&old) < 0)
	return NULL;

    return old.sa_handler;
}
