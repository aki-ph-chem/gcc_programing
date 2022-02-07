#include<unistd.h>
#include<stdlib.h>

#define BUFF_SIZE 2048

char buf[] = "Hi\n";

int main(){

    if(write(STDOUT_FILENO,buf,sizeof(buf)))exit(1);


}
