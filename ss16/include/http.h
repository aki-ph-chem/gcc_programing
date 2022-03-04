#ifndef _HTTP_H_
#define _HTTP_H_

#include<string.h>
#include<log.h>
#include<memory.h>

void free_request(struct HTTPRequest* req);

struct HTTPRequest* read_request(FILE* in);

void read_request_line(struct HTTPRequest *req,FILE *in);

long content_length(struct HTTPRequest* req);

char* lookup_header_field_value(struct HTTPRequest* req, char* name);

#endif //_HTTP_H_
