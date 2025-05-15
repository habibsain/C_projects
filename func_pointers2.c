#include<stdio.h>
#include<stdlib.h>

typedef void (*func_ptr)(void *a);

void gen_array_mapper(void *array, int n, int element_size, func_ptr func)
{
        for(int i = 0; i < n; i++)
        {
		void *element = (void *)( (char *) array + i * element_size);
                (*func)(element);
        }
}

int s = 0;

void sum_elements(void *el)
{
	int* element = (int *) el;
        s += *element;
}

void print_element(void *el)
{
	int* element = (int *) el;
        printf("The value is: %d\n", *element);
}

int main()
{
        int arr[] = { 1, 2, 3, 4, 5, 6};

        //print each element
        gen_array_mapper(arr, sizeof(arr)/sizeof(int), sizeof(int), print_element);


        //summ the elents to external var
        s = 0;
        gen_array_mapper(arr, sizeof(arr)/sizeof(int), sizeof(int), sum_elements);

        printf("The sum of all elements is: %d\n", s);
        return 0;
}

