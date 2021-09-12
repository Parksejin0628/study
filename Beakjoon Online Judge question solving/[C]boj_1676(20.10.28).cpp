//Number of Question : 1676
//Difficulty : Silver 4
//Time to solve : 16m 33s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int n=0;
	long long sum=1;
	
	scanf("%d",&n);
	printf("%d",(n/125) + (n/25)+ n/5);
	return 0;
}
