#ifndef _RESPONS_H_
#define _RESPONS_H_

#define TIME_BUF_SIZE 64

static struct Fileinfo* get_fileinfo(char* docroot,char* urlpath); 

static char* build_fspath(char* docroot, char* urlpath);

static void respond_to(struct HTTPRequest* req, FILE* out, char* docroot);

static void do_file_response(struct HTTPRequest* req, FILE* out, char* docroot);

static void output_common_fields(struct HTTPRequest* req, FILE* out, char* status);

#endif //_RESPONS_H_
