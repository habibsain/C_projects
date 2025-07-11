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

	dup2(fdpipe[0], 0);
        close(fdpipe[0]);
	
	int ret = fork();
	if(ret == 0)
	{
		//close(fdpipe[0]);
		//implement the ls command
		char *args[3];
		args[0] = "ls";
		args[1] = "-al";
		args[2] = NULL;

		//execute
		execvp(args[0], args);
		
		//error handling
		perror("execvp");
		_exit(1);
	}
	//redirect input for grep
	//dup2(fdpipe[0], 0);
	//close(fdpipe[0]);

	//create an outputfile to store the result
	int fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(fd < 0)
	{
		perror("Open");
		exit(1);
	}
	//redirect stdout to outfile
	dup2(fd, 1);
	close(fd);


	//implement grep over the output from prev child process
	
	ret = fork();
	if(ret == 0)
	{
		char *args[3];
		args[0] = "grep";
		args[1] = argv[1];
		args[2] = NULL;

		execvp(args[0], args);

		perror("execvp");
		_exit(1);//diff betn exit and _exit
	}


	//redirect output and input to original
	dup2(temp_in, 0);
	dup2(temp_out, 1);	

	waitpid(ret, NULL);
	printf("Completed");
}

