#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int val = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if( val < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(val,1);

	printf("This is written in /std_out but redirected to output file");

}

