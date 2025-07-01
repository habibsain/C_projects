#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int x = 1;
	int val = fork();
	if(val == 0)
	{
		const char *argv[3];
		argv[0] = "ls";
		argv[1] = "-al";
		argv[2] = NULL;
		execvp(argv[0], argv);
		
	}
	else if(val < 0)
	{
		perror("fork");
		exit(2);
	}
	else
		waitpid(val, NULL);


}

