#include "dyn_arr.h"
#include<stdio.h>
#include<stdlib.h>


darray *init_darray(size_t size)
{
    darray arr;
    arr.data = malloc(size);
    if(arr.data == NULL)
    {
        print("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    else
    {
        arr.current_num = 0;
    }
    arr.max_num = size;

    return &arr;
}

int resize_darray(darray *arr, size_t new_size)
{
    //darray array = *arr;
    arr->data = realloc( arr->data, new_size);
    if(arr->data == NULL)
    {
        print("Memory reallocation error");
        return 0;
    }
    else
    {
        arr->max_num = new_size;
        return 1;
    }
    
}

void append_darray(darray *arr, int element)
{
    if(arr->current_num >= arr->max_num - 2)
    {
        int x;
        do
        {
            x = resize_darray(arr, arr->max_num + sizeof(int) * MAX_SIZE);
            printf("Memory reallocated!");
        } while (x !=1);
    }
    else
    {
        *((int *)arr->data + arr->current_num) = element;
        arr->current_num += sizeof(int);
        
    }
    

}

void free_array(darray *arr)
{
    free(arr->data);
}
