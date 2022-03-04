#include<stdlib.h>
#include<memory.h>

void* xmalloc(size_t sz){

    void* p;

    p = malloc(sz);
    if(!p)log_exit("failed to allocate memory");
    return p;
}
