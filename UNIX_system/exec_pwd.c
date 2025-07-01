#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int x = 1;
	int val = fork();
	if(val == 0)
	{
		const char *argv[2];
		argv[0] = "pwd";
		
		argv[1] = NULL;
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

