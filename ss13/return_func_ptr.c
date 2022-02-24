#include<stdio.h>

typedef int (*func_ptr)(int);

func_ptr return_func_ptr(void);
int pp(int a);

int main(void){

    int (*f)(int) ;

    f = return_func_ptr();

    printf("res: %d\n",f(10));
    return 0;
}

func_ptr return_func_ptr(void){

    int (*f)(int) ;

    f = pp;

    return f;
}


int pp(int a){

    return ++a;
}
