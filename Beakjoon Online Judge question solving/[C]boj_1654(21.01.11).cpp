//Number of question : 1654
//Difficulty : Silver 3
//Time to solve : 1h 5m 3s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int length[10100] = {0};
int sort[10100] = {0};

long long calMaxLength(int n, int k, int maxLength)
{
	long long left = 1;
	long long right = maxLength;
	long long acount = 0;
	long long max = 0;
	long long mid = 0;
	
	while(left<=right)
	{
		mid = (left + right) / 2;
		//printf("right : %d, left : %d, mid : %d\n",right, left, mid);
		for(int i=0; i<k; i++)
		{
			acount += (length[i] / mid);
			//printf("%d\n", (length[i] / mid));
		}
	//	printf("acount : %lld\n",acount);
		if(acount < n)
		{
			right = mid - 1;
		}
		else if(acount >= n)
		{
			max = mid;
			left = mid + 1;
		}
		acount = 0;
	}
	
	return max;
}

int main(void)
{	
	int n=0;
	int k=0;
	int maxLength = 0;
	
	scanf("%d %d",&k, &n);
	for(int i=0; i<k; i++)
	{
		scanf("%d",&length[i]);
		if(maxLength<length[i])
		{
			maxLength = length[i];
		}
	}
	/*for(int i=0; i<k; i++)
	{
		printf("length[%d] : %d\n",i,length[i]);
	}*/
	//printf("--\n");
	printf("%lld\n",calMaxLength(n, k, maxLength));
	
	return 0;
}
