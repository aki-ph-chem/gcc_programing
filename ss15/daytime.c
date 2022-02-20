#include<stdio.h>


static int open_connction(char* host,char* service);

int main(int argc, char* argv[]){

    int sock;
    FILE* f;
    char buf[1024];

    sock = open_connection((argc > 1 ? argv[1]:"localhost"),"daytime");
    f = fdopen(sock,"r");
    if(!f){

	perror("fdopen(3)");
	exit(1);
    }

    fgets(buf,sizeof(buf),f);
    fclose(f);
    fputs(buf,stdout);
    exit(0);
}
