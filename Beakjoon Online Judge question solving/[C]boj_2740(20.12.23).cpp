//Number of question : 2740
//Difficulty : Bronze 1
//Time to solve : 21m 23s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	int n=0;
	int m=0;
	int k=0;
	int a[100][100] = {0};
	int b[100][100] = {0};
	int mul[100][100] = {0};
	int temp=0;
	
	scanf("%d %d", &n, &m);
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<m ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<k ; j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<k ; j++)
		{
			temp = 0;
			for(int l=0 ; l<m ; l++)
			{
				temp += a[i][l] * b[l][j];
			}
			mul[i][j] = temp;
		}
	}
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<k ; j++)
		{
			printf("%d ",mul[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
