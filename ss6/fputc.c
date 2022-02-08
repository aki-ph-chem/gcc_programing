#include<stdio.h>
#include<stdlib.h>

int main(void){

    char string[] = "Hello World\n";

    int i;
    for(i = 0; i < sizeof(string);i++){

	fputc((int)string[i],stdout);
    }
}
