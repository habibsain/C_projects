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
	
	int ret = fork();
	if(ret == 0)
	{
		close(fdpipe[0];
		//implement the ls command
		char *args[3];
		args[0] = "ls";
		args[1] = "-al";
		args[2] = NULL;

		//execute
		execvp(args[0], args);

		//error handling
		
	}
	//redirect output for grep
	dup2(fdpipe[0], 0);
	close(fdpipe[0]);

	//create an outputfile to store the result
	int fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(fd < 0)
	{
		perror("Open");
		exit(1);
	}

	//redirect output and input to original
	dup2(temp_int, 0);
	dup2(temp_out, 1);	
}

