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
	//save stdin and stdout file descrptors
	int temp_in = dup(0);
	int temp_out = dup(1);

	//make a pipe
	int fdpipe[2];
	pipe(fdpipe);

	//redirect stdout for first process
	dup2(fdpipe[1], 1);
	close(fdpipe[1]);

	
}

