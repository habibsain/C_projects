#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* arr[3];

	//arr =  malloc(4 * sizeof(int));
	for(int i = 0; i < 4; i++){
	printf("the address of a[%d] is %p\n", i, arr[i]);
	}

	
	//free(arr);

	return 0;
}
