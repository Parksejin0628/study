//number of question : 17626
//Difficulty : Silver 5
//Time to solve : 17m 48s
//Simple review : 

#include<stdio.h>

int calCase(int num, int start, int depth)
{
	int min = 99;
	int temp = 0; 
	
	if(num == 0)	return depth - 1;
	if(depth>4 || num < 1 )	return 5;
	for(int i=start; i>=1; i--)
	{
		temp = calCase(num - i*i, i, depth + 1);
		if(min > temp)	min = temp;
	}
	return min;
}

int main(void)
{
	int n = 0;
	
	scanf("%d",&n);
	printf("%d",calCase(n, 225, 1));
	//scanf("%d",&n);
	
	return 0;
}
