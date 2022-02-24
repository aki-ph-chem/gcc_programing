static void read_request_line(struct HTTPRequest *req,FILE *in){

    char* buf[LINE_BUF_SIZE];
    char *path,*p;

    if(!fgets(buf,LINE_BUF_SIZE,in))
	log_exit("no request line");
    
    p = strchr(buf,' ');
    if(!p) log_exit("parse error on request line (1):%s",buf);
    *p++ = '\0';
    req->mehtod = xmalloc(p - buf);
}
