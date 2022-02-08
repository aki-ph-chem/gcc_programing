#include<stdio.h>

int main(void){

    //標準入力から１バイト読んで標準出力する
    int a = fgetc(stdin);
    fputc(a,stdout);
    
}
