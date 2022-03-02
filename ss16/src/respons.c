static struct Fileinfo* get_fileinfo(char* docroot,char* urlpath){

    struct Fileinfo *info;
    struct stat st;


    info = xmalloc(sizeof(struct Fileinfo));
    info->path = build_fspath(docroot, urlpath);
    info->ok = 0;

    if(lstat(info->path,&st) < 0) return info;
    if(!S_ISREG(st.st_mode)) return info;

    info->ok = 1;
    info->size = st.st_size;

    return info;
} 

static char* build_fspath(char* docroot, char* urlpath){

    char *path;

    path = xmalloc(strlen(docroot) + 1 + strlen(urlpath) + 1);
    sprintf(path, "%s/%s",docroot, urlpath);
    return path;
}

static void respond_to(struct HTTPRequest* req, FILE* out, char* docroot){

    if(strcmp(req->method,"GET") == 0)
	do_file_response(req, out, docroot);
    else if(strcmp(req->method,"HEAD") == 0)
	do_file_response(req,out,docroot);
    else if(strcmp(req->method,"POST") == 0)
	method_not_allowed(req,out);
    else 
	not_implemented(req,out);
}

static void do_file_response(struct HTTPRequest* req, FILE* out, char* docroot){

    struct Fileinfo* info;

    info = get_fileinfo(docroot,req->path);
    if(!info->ok){

	free_fileinfo(info);
	not_found(req,out);
	return;
    }

    output_common_header_fields(req,out,"200 OK");
    fprintf(out,"Content-Length: %ld\r\n",info->size);
    fprintf(out,"Content-Type: %s\r\n",guess_content_type(info));
    fprintf(out, "\r\n");
    if(strcmp(req->method, "HEAD") != 0){

	int fd;
	char buf[BLOCK_BUF_SIZE];
	size_t n;

	fd = open(info->path, O_RDONLY);
	if(fd < 0)
	    log_exit("failed to open %s: %s",info->path, strerror(errno));
	for(;;){

	    n = read(fd,buf,BLOCK_BUF_SIZE);
	    if(n < 0)
		log_exit("failed to read %s: %s",info->path,strerror(errno));
	    if(n == 0)
		break;
	    if(fwrite(buf,n,1,out) < n)
		log_exit("failed to write to socket:%s",strerror(errno));
	}
	close(fd);
    }

    fflush(out);
    free_fileinfo(info);
}

static void output_common_fields(struct HTTPRequest* req, FILE* out, char* status){

    time_t t;
    struct tm *tm;
    char* buf[TIME_BUF_SIZE];

    t = time(NULL);
    tm = gtime(&t);
    if(!tm) log_exit("gmtime() failed: %s", strerror(errno));
    strftime(buf,TIME_BUF_SIZE,:"%a, %d %b %Y %H:%M:%S GMT",tm);
    fprintf(out,"HTTP/1.%d %s\r\n",HTTP_MINOR_VERSION,status);
    fprintf(out,"Date: %s\r\n",buf);
    fprintf(out,"Server: %s%s\r\n",SERVER_NAME,SERVER_VERSION);
    fprintf(out,"Connection: close\r\n");
}
