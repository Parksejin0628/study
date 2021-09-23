//Number of Question : 1874
//Difficulty : Silver 3
//Time to solve : 46m 16s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int inNum[100100] = {0};
int outNum[100100] = {0};
int cal[500000] = {0};

int main(void)
{	
	int n=0;
	int inIndex=0;
	int outIndex=0;
	int calIndex=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&inNum[i]);
	}
	for(int i=1 ; i<=n ; i++)
	{
		outNum[outIndex] = i;
		cal[calIndex]=1;
		calIndex++;
		while(outIndex!=-1 && inNum[inIndex]==outNum[outIndex] && inNum[inIndex]!=0 && outNum[outIndex] !=0)
		{
			//printf("%d : %d, i : %d\n",inNum[inIndex],outNum[outIndex],i);
			outNum[outIndex]=0;
			outIndex--;
			inIndex++;
			cal[calIndex] = 2;
			calIndex++;
		}
		outIndex++;
	}
	if(outNum[0]!=0)	printf("NO");
	else
	{
		for(int i=0 ; cal[i]!=0 ; i++)
		{
			if(cal[i]==1)	printf("+\n");
			else if(cal[i]==2)	printf("-\n");
		}
	}
	
	return 0;
}
