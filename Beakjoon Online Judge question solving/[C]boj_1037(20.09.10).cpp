//Number of Question : 1037
//Difficulty : Silver 5
//Time to solve : 27m 58s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int num=0;
	int n[55]={0};
	int min = 1000000;
	int max = 0;
	scanf("%d",&num);
	for(int i=0 ; i<num ; i++)
	{
		scanf("%d",&n[i]);
		if(n[i]>max)	max = n[i];
		if(n[i]<min)	min = n[i];
	}
	if(max==min)	printf("%d",min*min);
	else	printf("%d",min*max);
	
	return 0;
}
