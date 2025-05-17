#include"newp.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int arr[] = { 1, 2, 3, 4, 5};

	int x;

	x = sum_arr(arr, 5);

	printf("The sum is %d\n", x);
	printf("The elements of the array are following:\n");
	print_arr(arr, 5);

	return 0;
}
