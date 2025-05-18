#ifndef __DYN_ARR_
#define __DYN_ARR_

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct {
	int *data;
	size_t current_num; // current number of elements in darray
	size_t max_num; // max nuber of elements in darray
} darray;

//initialize the dynamic array
darray *init_darray(size_t size);

//resize the dynamic array
void resize_darray(darray *arr, size_t new_size);

//add element to the array
void append_darray(darray *arr, int element);

void free_array(darray *arr);

#endif
