//Number of question : 1300
//Difficulty : Gold 3
//Time to solve : 33m 47s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

long long min(long long a, long long b)
{
	return (a<b) ? a : b;
}

int main(void)
{	
	int n = 0;
	int k = 0;
	long long mid = 0;
	long long ans = 0;
	long long right = 0;
	long long left = 0;
	long long count = 0;
	
	scanf("%d %d",&n,&k);
	left = 1;
	right = (long long)n*(long long)n;
	while(left<=right)
	{
		mid = (left + right) / 2;
		for(int i=1; i<=n; i++)
		{
			count += min(mid/i, n);
		}
		//printf("mid : %lld / count : %lld\n", mid, count);
		if(count < k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			ans = mid;
		}
		count = 0;
	}
	printf("%d",ans);
	
	return 0;
}
