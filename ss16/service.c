
static void service(FILE* in,FILE* out,char* docroot){

    struct HTTPRequest* req;

    req = read_request(in);
    respond_to(req,out,docroot);
    free_request(req);
}
