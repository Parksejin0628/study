//Number of question : 1904
//Difficulty : Silver 3
//Time to solve : 43m 9s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int caseNum[1000010] = {1, 2};

int main(void)
{
	int n=0;
	
	scanf("%d",&n);
	for(int i=2 ; i<n ; i++)
	{
		caseNum[i] = (caseNum[i-1] + caseNum[i-2])%15746;
	}
	printf("%d",caseNum[n-1]);
	
	
	return 0;
}
