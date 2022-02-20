static void install_signal_handlers(void){

    trap_signal(SIGPIPE,signal_exit);
}

static void trap_signal(int sig, sighandler_t handler){

    struct sigaction act;

    act.sa_handler = handler;
    sigempty(&act.sa_mask);
}
