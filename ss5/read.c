#include<unistd.h>
#include<stdlib.h>

#define BUFF_SIZE 2048

unsigned char buf[BUFF_SIZE];

int main(void){

    int n;
    
    for(;;){

	n = read(STDIN_FILENO,buf,sizeof(buf));
	
	if(n < 0) exit(1);
	if(n == 0) break;
	if(write(STDOUT_FILENO,buf,n) < 0) exit(1);
    }

    if(close(STDIN_FILENO)) exit(1);


}
