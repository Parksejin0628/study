//number of question : 9095
//Difficulty : Silver 3
//Time to solve : 20m 44s
//Simple review : 

#include<stdio.h>

int numberOfCase[20] = {0, 1, 2, 4};

int calCase(int n)
{
	if(n<=0)	return 0;
	if(numberOfCase[n] != 0)
	{
		return numberOfCase[n];
	}
	return calCase(n-1) + calCase(n-2) + calCase(n-3);
}

int main(void)
{
	int testcase = 0;
	int n = 0;
	
	scanf("%d",&testcase);
	for(int t=1; t<=testcase; t++)
	{
		scanf("%d",&n);
		printf("%d\n",calCase(n));
	}
	
	return 0;
}
