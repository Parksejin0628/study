//Number of question : 17298
//Difficulty : Gold 4
//Time to solve : 18m 58s + @
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int a[1000100] = {0};
int stack[1000100] = {0};
int nge[1000100] = {0};

void calNGE(int n)
{
	int stackIndex = -1;
	for(int i=0; i<n; i++)
	{
		if(stackIndex == -1)
		{
			stack[++stackIndex] = i;
			continue;
		}
		while(a[stack[stackIndex]] < a[i] && stackIndex >= 0)
		{
			//printf("a[%d]의 오큰수 : %d\n",a[stack[stackIndex]], a[i]);
			nge[stack[stackIndex]] = a[i];
			stack[stackIndex] = 0;
			stackIndex--;
		}
		stack[++stackIndex] = i;
	}
	while(stackIndex >= 0)
	{
		nge[stack[stackIndex]] = -1;
		stackIndex--;
	}
}

int main(void)
{	
	int n=0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	calNGE(n);
	for(int i=0; i<n; i++)
	{
		printf("%d ",nge[i]);
	}
	
	return 0;
}
