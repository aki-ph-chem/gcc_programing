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

	if(req->length)
    }
}
