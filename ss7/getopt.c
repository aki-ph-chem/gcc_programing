#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

    int opt;

    while((opt = getopt(argc,argv,"af:t")) != -1){

	switch(opt){

	    case 'a':
		// case a
		break;

	    case 'f':
		// case b
		break;
		
	    case 't':
		// case t
		break;

	    case '?':
		// error
		break;
	}
    }

    // 何か処理
}
