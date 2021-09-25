//number of question : 11659
//Difficulty : Silver 3
//Time to solve : 31m 58s
//Simple review : 

#include<stdio.h>

int num[100100] = {0};
int sum[100100] = {0}; 

int main(void)
{
	int n = 0;
	int m = 0;
	int start = 0;
	int end = 0;
	
	scanf("%d %d",&n, &m);
	
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
		sum[i] = sum[i-1] + num[i];
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&start, &end);
		printf("%d\n", sum[end] - sum[start-1]);
	}
	
	//scanf("%d",&n);
	
	return 0;
}
