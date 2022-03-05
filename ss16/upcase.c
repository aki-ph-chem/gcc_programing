#include<stdio.h>
#include<ctype.h>

void upcase(char* str);

int main(void){

    char str[] = "abcdefg";
    char* str_2 = str;
    upcase(str_2);

    printf("%s\n",str);
    return 0;
}

void upcase(char* str){

    char *p;

    for(p = str; *p; p++){

	*p = (char)toupper((int)*p);
    }
}
