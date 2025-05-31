#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int x = 1;
	int val = fork();
	if(val == 0)
	{
		printf("This is the child process: %d\n", ++x);
	}
	else
		printf("Parent : %d\n", --x);
}

