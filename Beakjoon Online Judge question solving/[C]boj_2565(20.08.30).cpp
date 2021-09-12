//Number of Question : 2565
//Difficulty : Silver 1
//Time to solve : 36m 41
//Simple review : 


#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void calOptimalSum_up();
void calOptimalSum_down();

int n=0;
int wire[501]={0};
int optimalSum_up[501]={0};
int optimalSum_down[501]={0};
int sumMax_up=0;
int sumMax_down=0;

void calOptimalSum_up()
{
	int max=0;
	int acount=0;
	
	for(int i=1 ; i<=500 ; i++)
	{
		if(n-acount<=0)	break;
		if(wire[i]!=0)
		{
			acount--;
			for(int j=0 ; j<i ; j++)
			{
				if(wire[j] < wire[i] && wire[j]!=0 && optimalSum_up[j] > max)
				{
					max = optimalSum_up[j];
				}
			}
			optimalSum_up[i] = max + 1;
			if(optimalSum_up[i] > sumMax_up)	sumMax_up = optimalSum_up[i];
			max=0;
		}
	}
	
	return;
}

void calOptimalSum_down()
{
	int max=0;
	int acount=0;
	
	for(int i=500 ; i>=1 ; i--)
	{
		if(n-acount<=0)	break;
		if(wire[i]!=0)
		{
			acount--;
			for(int j=i+1 ; j>=1 ; j--)
			{
				if(wire[j] < wire[i] && wire[j]!=0 && optimalSum_down[j] > max)
				{
					max = optimalSum_down[j];
				}
			}
			optimalSum_down[i] = max + 1;
			if(optimalSum_down[i] > sumMax_down)
			{
				sumMax_down = optimalSum_down[i];
			//	printf("check1 %d %d\n",i,wire[i]);
			}
			max=0;
		}
	}
	
	return;
}


int main(void)
{
	int a=0;
	int b=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d %d",&a,&b);
		wire[a] = b;
	}
	calOptimalSum_up();
	calOptimalSum_down();
//	printf("%d %d\n",sumMax_up, sumMax_down);
	
	printf("%d",n-((sumMax_up > sumMax_down) ? sumMax_up : sumMax_down));
	
	return 0;
}
