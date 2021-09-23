//Number of question : 6549
//Difficulty : Platinum 5
//Time to solve : 1h 30m
//Simple review : So hard / long long = int * int : IF int * int > 2147483647, Overflow

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int h[100100] = {0};
long long stack[100100][2] = {0};

long long calArea(int n)
{
	int index = 0;
	long long temp = 0;
	long long max = 0;
	int preTurn = -1;
	for(int turn=0; turn<n; turn++)
	{
		preTurn = -1;
		while(h[turn] < stack[index][0])
		{
			preTurn = stack[index][1];
			temp = stack[index][0] * (turn - stack[index][1]);
			//printf("%d * %d = %d\n",stack[index][0], turn - stack[index][1], temp);
			//printf("num : %d turn : %d, stackTurn : %d\n", stack[index][0], turn, stack[index][1]);
			if(max < temp)
			{
				max = temp;
			}
			index--;
		}
		if(h[turn] > stack[index][0])
		{
			index++;
			stack[index][0] = h[turn];
			stack[index][1] = preTurn;
			if(preTurn==-1)
			{
				stack[index][1] = turn;
			}
		}
	}
	while(index>0)
	{
		temp = stack[index][0] * (n - stack[index][1]);
		//printf("%d * %d = %d\n",stack[index][0], n - stack[index][1],temp);
		if(max < temp)
		{
			max = temp;	
		}
		index--;
	}
	
	return max;
}

int main(void)
{	
	int n=0;
	
	while(true)
	{
		scanf("%d",&n);
		if(n==0)	break;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&h[i]);			
		}
		printf("%lld\n",calArea(n));
	}
	
	return 0;
}
