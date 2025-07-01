#include"dyn_arr.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int arr[] = { 5, 4, 3, 2, 1, 6};

	darray* new_arr;
	
	//We have initialised an array of size 5
	//But the darray dynamically changes size to append data as per requirent
	new_arr = init_darray(5);

	for(int i = 0; i < 6; i++)
	{
		//We are appending arr[6] elements into new_arr[5] 
		append_darray(new_arr, arr[i]);
		int val = new_arr->data [i];
		printf("The element darr[%d] is: %d\n", i, val);
	}
	printf("Hello\n");
	free_array(new_arr);


	// int x;

	// x = sum_arr(arr, 5);

	// printf("The sum is %d\n", x);
	// printf("The elements of the array are following:\n");
	// print_arr(arr, 5);

	return 0;
}
