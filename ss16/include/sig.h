#ifndef _SIG_H_
#define _SIG_H_

#include<signal.h>
#include<log.h>

void install_signal_handlers(void);

void trap_signal(int sig, sighandler_t handler);

void signal_exit(int sig);

void service(FILE* in,FILE* out,char* docroot);

#endif //_SIG_H_
