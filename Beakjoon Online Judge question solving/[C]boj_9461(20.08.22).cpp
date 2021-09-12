//Number of question : 9461
//Difficulty : Silver 3
//Time to solve : 5m 59s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

long long caseNum[100] = {1, 1, 1, 2, 2};

int main(void)
{
	int t=0;
	int n=0;
	scanf("%d",&t);
	for(int i=5 ; i<100 ; i++)
	{
		caseNum[i] = caseNum[i-1] + caseNum[i-5];
	}
	for(int i=0 ; i<t ; i++)
	{
		scanf("%d",&n);
		printf("%lld\n",caseNum[n-1]);
	}
	
	
	return 0;
}
