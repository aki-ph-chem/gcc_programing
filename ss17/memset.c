#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    char buf[] = "Hello!";

    // bufの頭から1バイト進めたところにAを3バイト書き込む
    memset(buf + 1,'A',3);

    printf("Hello -> %s\n",buf);

    return 0;
}
