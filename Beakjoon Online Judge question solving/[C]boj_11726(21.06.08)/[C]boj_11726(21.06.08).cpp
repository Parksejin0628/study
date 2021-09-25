//number of question : 11726
//Difficulty : Silver 3
//Time to solve : 9m 3s
//Simple review : 

#include<stdio.h>

int memoization[1010] = {0, 1, 2};

int calCase(int n)
{
	if(n<=0)	return 0;
	if(memoization[n]==0)	memoization[n] = (calCase(n-1) + calCase(n-2))%10007;
	
	return memoization[n];
}

int main(void)
{
	int n = 0;
	
	scanf("%d",&n);
	printf("%d",calCase(n));
//	scanf("%d",&n); 
	
	return 0;
}
