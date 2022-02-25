#ifndef _HTTP_H_
#define _HTTP_H_

#include<string.h>

static void free_request(struct HTTPRequest* req);

static struct HTTPRequest* read_request(FILE* in);

static void read_request_line(struct HTTPRequest *req,FILE *in);

#endif //_HTTP_H_
