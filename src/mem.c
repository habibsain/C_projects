#include<stdio.h>
#include<stdlib.h>
#include "../include/mem.h"

void* NEW(size_t size)
{
    void* ptr = malloc(size);

    if(ptr == NULL)
    {
        fprintf(stderr,"Memory allocation error");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void FREE(void* ptr)
{
    if(ptr != NULL)
    {
        free(ptr);
        ptr = NULL;
    }
    else
        fprintf(stderr, "Ptr is unallocated");
}