//Number of question : 14889
//Difficulty : Silver 3
//Time to solve : 47m 20s + @(more time)
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int n=0;
int s[20][20] = {0};
int min=1000000000;
int selectedNum[11] = {0};
int unSelectedNum[11] = {0};
int checkNum[20] = {0};

void calStats()
{
	int temp=1;
	int sum1=0;
	int sum2=0;
	int difference=0;
	
	for(int i=1 ; i<=n ; i++)
	{
		if(checkNum[i]==0)
		{
			unSelectedNum[temp]=i;
			//printf("비선정된 숫자 : %d\n",i);
			temp++;
		} 
	}	
	for(int i=1 ; i<=n/2-1 ; i++)
	{
		for(int j=1+i ; j<=n/2 ; j++)
		{
			sum1 += s[selectedNum[i]-1][selectedNum[j]-1] + s[selectedNum[j]-1][selectedNum[i]-1];
			sum2 += s[unSelectedNum[i]-1][unSelectedNum[j]-1] + s[unSelectedNum[j]-1][unSelectedNum[i]-1];
			//printf("현재 능력치합 : %d %d\n",sum1,sum2);
		}
	}
	difference=sum1-sum2;
	if(difference<0)	difference*=-1;
	//printf("선정된 숫자의 합 : %d, 비선정된 숫자의 합 : %d, 차이값 : %d\n",sum1, sum2, difference);
	if(difference<min)	min = difference;
	return;
}

void selectNum(int num)
{
	for(int i=selectedNum[num-1]+1 ; i<=num + n/2 ; i++)
	{
		selectedNum[num] = i;
		checkNum[i] = 1;
		//printf("%d번째로 선정된 숫자는 %d\n",num,i);
		if(num == n/2)	calStats();
		else selectNum(num+1);
		checkNum[i]=0;
	}
	return;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			scanf("%d",&s[j][i]);
		}
	}
	selectNum(1);
	printf("%d",min);
	
	return 0;
}
