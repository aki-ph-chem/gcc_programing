//signal処理１
static void install_signal_handlers(void){

    trap_signal(SIGPIPE,signal_exit);
}

//signal処理2
static void trap_signal(int sig, sighandler_t handler){

    struct sigaction act;

    act.sa_handler = handler;
    sigempty(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    if(sigaction(sig,&act,NULL) < 0)
	log_exit("sigaction()failed: %s",strerror(errno));
}

//signal処理3
static void signal_exit(int sig){

    log_exit("exit by signal %d",sig);
}

