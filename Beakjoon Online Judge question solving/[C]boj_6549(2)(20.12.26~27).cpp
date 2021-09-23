//Number of question : 6549
//Difficulty : Platinum 5
//Time to solve : 3h 24m 15s
//Simple review : Divide and conquer algorithm

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int h[100100] = {0};
int segmentTree[400400] = {0};
long long max = 0;

int init(int node, int start, int end)
{
	//printf("check1\n");
	if(start == end)
	{
		//printf("node : %d - %d\n",node, start);
		return segmentTree[node] = start;
	}
	int min = 0;
	int mid = (start + end) / 2;
	int temp1 = init(node*2, start, mid);
	int temp2 = init(node*2+1, mid+1, end);
	if(h[temp1] < h[temp2])
	{
		min = temp1;
	}
	else
	{
		min = temp2;
	}
	
	//printf("node : %d - %d\n",node, min);
	return segmentTree[node] = min;
}

long long query(int node, int start, int end, int left, int right)
{
	//printf("check2\n");
	if(right<start || end<left)
	{
		return -1;
	}
	if(left<=start && end<=right)
	{
		return segmentTree[node];
	}
	if(start == end)
	{
		return segmentTree[node];
	}
	int mid = (start + end) / 2;
	long long temp1 = query(node*2, start, mid, left, right);
	long long temp2 = query(node*2+1, mid+1, end, left, right);
	if(temp1 == -1)
	{
		return temp2;
	}
	else if(temp2 == -1)
	{
		return temp1;
	}
	if(h[temp1]<h[temp2])
	{
		return temp1;
	}
	else
	{
		return temp2;
	}
}

void calArea(int start, int end, int n)
{
	long long temp = 0;
	int lowHeight = query(1, 0, n-1, start, end);
	//printf("check3 start : %d, end : %d, lowHeight : %d\n",start,end, lowHeight);
	temp = (long long)(end - start + 1) * (long long)h[lowHeight];
	//printf("start : %d, end : %d lowHeight : %d temp : %lld\n", start, end, h[lowHeight], temp);
	if(temp > max)
	{
		max = temp;
	}
	if(start == end)
	{
		return;
	}
	if(start<lowHeight)
	{
		calArea(start, lowHeight-1, n);
	}
	if(lowHeight<end)
	{
		calArea(lowHeight+1, end, n);
	}
	
	return;
}

int main(void)
{	
	int n=-1;
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d",&h[i]); 
		}
		init(1, 0, n-1);
		max = 0;
		calArea(0, n-1, n);
		printf("%lld\n",max);
	}
	
	return 0;
}
