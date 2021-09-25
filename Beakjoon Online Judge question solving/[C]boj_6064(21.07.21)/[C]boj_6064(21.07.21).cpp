//number of question : 6064
//Difficulty : Silver 1
//Time to solve : 9m 15s
//Simple review : 

#include<stdio.h>

int main(void)
{
	int m = 0;
	int n = 0;
	int x = 0;
	int y = 0;
	int testcase = 0;
	int temp = 0;
	
	scanf("%d",&testcase);
	for(int t=1; t<=testcase; t++)
	{
		scanf("%d %d %d %d",&m, &n, &x, &y);
		if(m==x)
		{
			x = 0;
		}
		if(n==y)
		{
			y = 0;
		}
		for(int i=0; i<=40000; i++)
		{
			temp = m*i + x;
			if(temp > m*n)
			{
				printf("-1\n");
				break;
			}
			if(temp % n == y)
			{
				printf("%d\n", temp);
				break;
			}
		}
	}
	scanf("%d",&n); 
	
	return 0;
}
