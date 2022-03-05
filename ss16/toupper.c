#include<stdio.h>
#include<ctype.h>

int main(void){
    
    char a = 'b';
    char b;

    b = (char)toupper((int)a);
    printf("%c\n",b);

    return 0;
}
