#include<signal.h>

typedef void (*singhandler_t)(int);

sighandler_t trap_signal(int sig, singhandler_t handler){

    struct sigaction act, old;

    //(1)シグナルハンドラーをsa_handlerに設定する。
    act.sa_handler = handler;
    //(2) sigemmptyset()でsa_maskを空に初期化
    sigemptyset(&act.sa_mask);
    //(3)　自動的な再起動を有効化するためにsa_flagsにSA_RESTARTを設定する。
    sa.sa_flags = SA_RESTART;
    if(sigaction(sig,&act,&old) < 0)
	return NULL;

    return old.sa_handler;
}
