#include<stdio.h>

int (*return_func_ptr(void))(int);
int  pp(int a);

int main(void){

    int(*func_ptr)(int);

    func_ptr = return_func_ptr();

    printf("resul: %d\n",func_ptr(10));

    return 0;
}

int (*return_func_ptr(void))(int){

    int(*f)(int);

    f = pp;
    return f;
}

int pp(int a){

    return ++a;
}
