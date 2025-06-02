#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char **argv)
{
	if(argc < 3)
	{
		fprintf(stderr, "Try: lsgrep arg1 arg2\n");
		exit(1);
	}

	
}

