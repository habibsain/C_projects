#include"newp.h"
#include<stdio.h>
#include<stdlib.h>


void print_arr(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\n",a[i]);
	}
}

int sum_arr(int *b, int n)
{
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += b[i];
	}
	return s;
}
