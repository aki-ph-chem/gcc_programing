#include<stdio.h>

int add_two_num(int a, int b);

int main(void){

    int (*f)(int,int);

    f = add_two_num;
    printf("%d\n",f(1,1));
}

int add_two_num(int a, int b){

    int res = a + b;
    return res;
}
