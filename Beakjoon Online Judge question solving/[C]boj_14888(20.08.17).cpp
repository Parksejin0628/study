//Number of question : 14888
//Difficulty : Silver 1
//Time to solve : 47m 5s
//Simple review :  

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
int sequence[11] = {0};
int operNum[4] = {0};
int sum[11] = {0};
int min = 1000000000;
int max = -1000000000;
int n=0;

void calculation(int num)
{
	if(num==1)
	{
		sum[0] = sequence[0];
	}
	if(operNum[0]>0)
	{
		operNum[0]--;
		sum[num] = sum[num-1] + sequence[num];
		calculation(num+1);
		operNum[0]++;
	}
	if(operNum[1]>0)
	{
		operNum[1]--;
		sum[num] = sum[num-1] - sequence[num];
		calculation(num+1);
		operNum[1]++;
	}
	if(operNum[2]>0)
	{
		operNum[2]--;
		sum[num] = sum[num-1] * sequence[num];
		calculation(num+1);
		operNum[2]++;
	}
	if(operNum[3]>0)
	{
		int negative[2]={0};
		if(sum[num-1]<0)
		{
			sum[num-1]*=-1;
			negative[0]++;
		}
		if(sequence[num]<0)
		{
			sequence[num]*=-1;
			negative[1]++;
		}
		operNum[3]--;
		sum[num] = sum[num-1] / sequence[num];
		if(negative[0] + negative[1] == 1)	sum[num]*=-1;
		if(negative[0]>0)	sum[num-1]*=-1;
		if(negative[1]>0)	sequence[num]*=-1; 
		calculation(num+1);
		operNum[3]++;
	}
	if(num==n-1)
	{
		if(sum[num]>max)	max=sum[num];
		if(sum[num]<min)	min=sum[num];
	}
	
	return;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d",&sequence[i]);
	}
	for(int i=0 ; i<4 ; i++)
	{
		scanf("%d",&operNum[i]);
	}
	calculation(1);
	printf("%d\n%d",max,min);
	
	
	return 0;
}
