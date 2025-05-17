#include "dyn_arr.h"
#include<stdio.h>
#include<stdlib.h>


darray *init_darray(size_t size)
{
    darray *arr;
    arr = malloc(sizeof(darray));
    if(arr == NULL)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    arr->data = malloc(size);
    if(arr->data == NULL)
    {
        printf("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    else
    {
        arr->current_num = 0;
    }
    arr->max_num = size;

    return arr;
}

void resize_darray(darray *arr, size_t new_size)
{
    //darray array = *arr;
    arr->data = realloc( arr->data, new_size);
    if(arr->data == NULL)
    {
        printf("Memory reallocation error");
        exit(EXIT_FAILURE);
    }
    else
    {
        arr->max_num = new_size;
    }
    
}

void append_darray(darray *arr, int element)
{
    if(arr->current_num >= arr->max_num - 2)
    {
        int x;
        do
        {
            resize_darray(arr, arr->max_num + sizeof(int) * MAX_SIZE);
            printf("Memory reallocated!\n");
        } while (x !=1);
    }
    
    
    *((int *)arr->data + arr->current_num) = element;
    arr->current_num += sizeof(int);
        
    
    

}

void free_array(darray *arr)
{
    free(arr->data);
    arr->data = NULL;
    free(arr);
    arr = NULL;
}
