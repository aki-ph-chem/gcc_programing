#include<stdio.h>

int sq_func(int a);
int liner_func(int c);

int nume_dif(int (*f)(int),int val,int h);

int main(void){

    printf("%d\n",nume_dif(sq_func,1000,1));
    printf("%d\n",nume_dif(liner_func,10,1));

    return 0;
}

int sq_func(int a){

    int res = a*a + 1;
    return res;
}

int liner_func(int c){

    int coff = 1;
    int res;
    res = coff*c;
    return res;
}

int nume_dif(int (*f)(int),int val,int h){

    int res;
    res = f(val + h) - f(val);
    res = res/h;

    return res;
}
