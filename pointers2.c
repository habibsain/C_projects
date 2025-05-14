#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sum(int *arr, int n)
{
	int result = 0;
	int *p = &arr[0];
	int *pend = &arr[n];

	while(p < pend)
	{
		result += *p;
		p++;
	}
	return result;

}

int main()
{
	clock_t before, end;

	before = clock();

	int vec[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	int summ;

	summ = sum(vec, 55);

	printf("The sum is: %d\n", summ);
	
        end = clock();
        long double cpu_time =  ((long double) (end - before)) / CLOCKS_PER_SEC;
        printf("Time consumed: %Lf\n", cpu_time);

	return 0;
}
