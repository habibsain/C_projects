#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	float x[2] = {1, 2};
	printf("%p\n", x);
	printf("%p\n", x+1);
	return 0;
}
