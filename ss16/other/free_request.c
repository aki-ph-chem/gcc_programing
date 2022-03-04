
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

//これはやっちゃダメ
/*
 for(h = req->header; h; h = h->next){

 free(h);
 }
 */

