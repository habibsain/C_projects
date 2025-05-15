#include<stdio.h>
#include<stdlib.h>

typedef void (*func_ptr)(int a);

void array_mapper(int *array, int n, func_ptr func)
{
	for(int i = 0; i < n; i++)
	{
		(*func)(array[i]);
	}
}

int s = 0;

void sum_elements(int element)
{
	s += element;
}

void print_element(int element)
{
	printf("The value is: %d\n", element);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5};
	
	//print each element
	array_mapper(arr, sizeof(arr)/sizeof(int), print_element);
	

	//summ the elents to external var
	s = 0;
	array_mapper(arr, sizeof(arr)/sizeof(int), sum_elements);

	printf("The sum of all elements is: %d\n", s);
	return 0;
}

