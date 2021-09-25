//number of question : 11727
//Difficulty : Silver 3
//Time to solve : 9m 6s
//Simple review : 

#include<stdio.h>

int caseNum[1010] = {0, 1, 3};

int calCase(int num)
{
	if(num <= 0)	return 0;
	
	if(caseNum[num] == 0)
	{ 
		caseNum[num] = (calCase(num-1) + calCase(num-2) * 2) % 10007;
	}
	
	return caseNum[num];
}

int main(void)
{
	int n = 0;
	
	scanf("%d",&n);
	printf("%d\n",calCase(n));
	scanf("%d",&n);
	
	return 0;
}
