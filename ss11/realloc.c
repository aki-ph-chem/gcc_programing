#include<stdio.h>
#include<stdlib.h>

int main(void){

    int* heap;
    size_t mem_size = 2;

    heap = (int*)malloc(sizeof(int)*mem_size);
    if(!heap){

	fprintf(stderr,"memory error\n");
	exit(1);
    }

    mem_size *= 2;

    heap = (int*)realloc(heap,mem_size);
    if(!heap){

	fprintf(stderr,"memory error\n");
	exit(1);
    }

    free(heap);
}
