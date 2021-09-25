//number of question : 18111
//Difficulty : Silver 3
//Time to solve : 33m 36s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int land[550][550] = {0};
int n=0;
int m=0;
int b = 0;

int flatland(int height)
{
	int block = b;
	int useBlock = 0;
	int sum = 0;
	
	for(int j=0; j<m; j++)
	{
		for(int i=0; i<n; i++)
		{
			if(land[i][j]>height)
			{
				sum += (land[i][j] - height) * 2;
				block += land[i][j] - height;
			}
			else if(land[i][j]< height)
			{
				sum += height - land[i][j];
				useBlock += height - land[i][j];
			}
		}
	}
	//printf("check1- height : %d, sum : %d\n",height, sum);
	if(block < useBlock)	return -1;
	else	return sum;
}

int main(void)
{
	int high = 0;
	int low = 300;
	int min = -1;
	int height = 0;
	int temp = 0;
	
	scanf("%d %d %d",&n, &m, &b);
	for(int j=0; j<m; j++)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&land[i][j]);
			if(high < land[i][j])	high = land[i][j];
			if(low > land[i][j])	low = land[i][j];
		}
	}
	
	for(int i=low; i<=high; i++)
	{
		temp = flatland(i);
		if(min == -1 || min > temp && temp != -1)
		{
			min = temp;
			height = i;
		}
		else if(min == temp)	height = i;
	}
	printf("%d %d\n",min, height);
	//scanf("%d",&n);
	
	return 0;
}
