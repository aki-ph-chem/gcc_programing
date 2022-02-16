#include<stdio.h>
#include<stdlib.h>

int main(void){

    int* ptr_1;
    int* ptr_2;

    ptr_1 = (int*)malloc(sizeof(int)*2);
    
    if(!ptr_1){

	fprintf(stderr,"memory error");
	exit(1);
    }
   
    ptr_2 = (int*)calloc(1,sizeof(int)*2);

    if(!ptr_2){

	fprintf(stderr,"memory error");
	exit(1);
    }

    for(int i=0; i < 2; i++){

	printf("value of ptr_1 is %d\n",ptr_1[i]);
    }
    
    for(int i=0; i < 2; i++){

	printf("value of ptr_2 is %d\n",ptr_2[i]);
    }

    free(ptr_1);
    free(ptr_2);
}
