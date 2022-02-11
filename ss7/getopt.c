#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

    int opt;

    int num = 666;

    while((opt = getopt(argc,argv,"afg:")) != -1){

	switch(opt){

	    case 'a':
		// case a
	        num = 114;	
		break;

	    case 'f':
		// case b
	        num =514;	
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

    printf("num = %d\n",num);

    // 何か処理
}
