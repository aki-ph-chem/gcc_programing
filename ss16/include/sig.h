#ifndef _SIG_H_
#define _SIG_H_

static void install_signal_handlers(void);

static void trap_signal(int sig, sighandler_t handler);

static void signal_exit(int sig);

static void service(FILE* in,FILE* out,char* docroot);

#endif //_SIG_H_
