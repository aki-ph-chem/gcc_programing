#include<getopt.h>
#include<stdio.h>
#include<stdlib.h>

#define _GNU_SOURCE

static struct option longopts[] = {

    {"a_num",no_argument,NULL,'a'},
    {"b_num",required_argument,NULL,'b'},
    {0,0,0,0}
};

int main(int argc, char* argv[]){

    int opt;
    int num = 666;

    while((opt = getopt_long(argc, argv, "ab:fg:",longopts,NULL)) != -1){

	switch(opt){

	    case 'a':
		// case a
		num = 114;
		break;

	    case 'b':
		// case b
		num = atoi(optarg);
		break;

	    case 'f':
		// case f
		num = 514;
		break;

	    case 'g':
		// case g
		num = atoi(optarg);
		break;

	    case '?':
		// error
		break;
	}
    }

    printf("num is %d\n",num);

}
