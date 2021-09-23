//Number of question : 2110
//Difficulty : Silver 1
//Time to solve : 1h 12m 56s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int x[200200] = {0};
int sort[200200] = {0};

void mergeSort(int start, int end)
{
	if(start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	
	for(; k<=end; k++)
	{
		if(x[i] <= x[j])
		{
			sort[k] = x[i];
			i++;
		}
		else
		{
			sort[k] = x[j];
			j++;
		}
		if(i>mid || j>end)
		{
			k++;
			break;
		}
	}
	if(j>end)
	{
		for(; k<=end; k++)
		{
			sort[k] = x[i];
			i++;
		}
	}
	else if(i>mid)
	{
		for(; k<=end; k++)
		{
			sort[k] = x[j];
			j++;
		}
	}
	for(int k=start; k<=end; k++)
	{
		x[k] = sort[k];
	}
}

int calMaxDist(int n, int c)
{
	int left = 1;
	int right = x[n-1];
	int mid = 0;
	int max = 0;
	int count = 1;
	int index = 0;
	
	while(left<=right)
	{
		mid = (left + right) / 2;
		//printf("left : %d, right : %d, mid : %d, max : %d\n",left, right, mid, max);
		for(int i=1; i<n; i++)
		{
			//printf("mid : %d, dist : %d\n",mid, x[i] - x[index]);
			if(x[i] - x[index] >= mid)
			{
				index = i;
				count++;
			}
			if(count>=c)
			{
				break;
			}
		}
		if(count >= c)
		{
			left = mid + 1;
			max = mid;
		}
		else
		{
			right = mid - 1;
		}
		index = 0;
		count = 1;
	}
	
	return max;
}

int main(void)
{	
	int n = 0;
	int c = 0;
	
	scanf("%d %d",&n,&c);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x[i]);
	}
	mergeSort(0, n-1);
	printf("%d\n",calMaxDist(n, c));
	
	return 0;
}
