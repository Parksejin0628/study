//Number of question : 1966
//Difficulty : Silver 3
//Time to solve : 33m 32s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	int t=0;
	int n=0;
	int m=0;
	int temp=0;
	int firstIndex=0;
	int rearIndex=0;
	int find=0;
	int acount=1;
	int num[120] = {0};
	int priority[10] = {0}; 
	
	scanf("%d",&t);
	for(int testcase=0 ; testcase<t ; testcase++)
	{
		scanf("%d %d",&n,&m);
		for(int i=0 ; i<n ; i++)
		{
			scanf("%d",&temp);
			num[i] = temp;
			priority[temp]++;
		}
		rearIndex = n-1;
		for(int i=9 ; i>=1 ; i--)
		{
			while(priority[i]>0)
			{
				//printf("�߿䵵 : %d / firstIndex : %d / rearIndex : %d / m : %d / num : %d\n",i,firstIndex,rearIndex,m,num[firstIndex%120]);
				if(num[firstIndex%120]==i)
				{
					if(firstIndex==m)
					{
						find=1;
						printf("%d\n",acount);
						break;
					}
					else
					{
						priority[i]--;
						firstIndex++;
						acount++;
					}
				}
				else
				{
					if(firstIndex==m)
					{
						m=rearIndex+1;
					}
					num[++rearIndex%120] = num[firstIndex++%120];
				}
			}
			if(find==1)	break;
		}
		firstIndex=0;
		rearIndex=0;
		find=0;
		acount=1;
		for(int i=0 ; i<120 ; i++)
		{
			if(i<10)
			{
				priority[i]=0;
			}
			num[i]=0;
		}
	}
	
	return 0;
}
