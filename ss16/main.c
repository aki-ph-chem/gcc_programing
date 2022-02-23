#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

static void log_exit(char* fmt,...);
static void* xmalloc(size_t sz);

static void trap_signal(int sig, sighandler_t handler);
static void signal_exit(int sig);
static void install_signal_handlers(void);

static void service(FILE* in,FILE* out,char* docroot);

static void free_request(struct HTTPRequest* req);

static struct HTTPRequest* read_request(FILE* in);



int main(int argc, char* argv[]){

    if(argc != 2){

	fprintf(stderr,"Usage %s <docroot>\n",argv[0]);
	exit(1);
    }

    install_signal_handler();
    service(stdin,stdout,argv[1]);
    exit(1);
}

// ...は可変引数の宣言
static void log_exit(char* fmt,...){

    // (1) va_listの宣言
    va_list ap;

    // (2) 使う前に呼ぶ
    va_start(ap,fmt);
    // (3) va_listを使う
    vprintf(stderr,fmt,ap);
    fputc('\n',stderr);
    // (4) 使た後に呼ぶ
    va_end(ap);
    exit(1);
}

//メモリ確保
static void* xmalloc(size_t sz){

    void* p;

    p = malloc(sz);
    if(!p)log_exit("failed to allocate memory");
    return p;
}


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

static void service(FILE* in,FILE* out,char* docroot){

    struct HTTPRequest* req;

    req = read_request(in);
    respond_to(req,out,docroot);
    free_request(req);
}

//メモリ開放
static void free_request(struct HTTPRequest* req){

    struct HTTPHeaderField *h,*head;

    head = req->header;
    while(head){

	h = head;
	head = head->next;
	free(h->name);
	free(h->value);
	free(h);
    }

    free(req->method);
    free(req->path);
    free(req->body);
    free(req);
}

//リクエストを読む
static struct HTTPRequest* read_request(FILE* in){

    struct HTTPRequest*  req;
    struct HTTPHeader*  h;

    req = xmalloc(sizeof(struct HTTPRequest));
    read_request_line(req, in);
    req->header = NULL;
    while(h = read_header_field(in)){

	h->next = req->header;
	req->header = h;
    }
    req->length = content_length(req);
    if(req->length != 0){

	if(req->length > MAX_REQUEST_BODY_LENGTH)
	    log_exit("request body too long");
	req->body = xmalloc(req->length);
	if(fread(req->body,req->length,1,in) < 1)
	    log_exit("failed to read request body");
    }else{

	req->body = NULL;
    }

    return req;
}
