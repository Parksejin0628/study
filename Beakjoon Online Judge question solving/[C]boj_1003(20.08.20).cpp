//Number of question : 1003
//Difficulty : Silver 3
//Time to solve : 15m 52s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES


int main(void)
{
	int count0[50]= {1,0,1};
	int count1[50]= {0,1};
	int t=0;
	int n=0;
	scanf("%d",&t);
	for(int a=0 ; a<t ; a++)
	{
		scanf("%d",&n);
		for(int i=0; i<=n ; i++)
		{
			if(i>=2)
			{
				count1[i] = count1[i-2] + count1[i-1];
				if(i>=3)
				{
					count0[i] = count0[i-2] + count0[i-1]; 
				}
			}
		}
		printf("%d %d\n",count0[n],count1[n]);
	}
	
	return 0;
}
