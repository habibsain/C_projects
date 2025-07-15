#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char var[] = "hello:hi";;
	
	char *p;
	p = strstr(var, ":h");
	*p = 0;
	p++;
	int x = strcmp("hello", var);
	printf("%d\n", x);
	printf("%c\n", *p);
	// float x[2] = {1, 2};
	// printf("%p\n", x);
	// printf("%p\n", x+1);
	return 0;
}
