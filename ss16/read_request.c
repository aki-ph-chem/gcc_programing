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
