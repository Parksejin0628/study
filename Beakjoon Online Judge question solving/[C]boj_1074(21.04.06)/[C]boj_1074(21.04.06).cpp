//number of question : 1074
//Difficulty : Silver 1
//Time to solve : 56m 51s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int r = 0;
int c = 0;

int square2(int num)
{
	int temp = 1;
	for(int i=0; i<num; i++)
	{
		temp *= 2;
	}
	return temp;
}

int checkQuadrant(int size, int startX, int startY)
{
	if(size == -1) 
	{
		//printf("check1\n");
		return 0;
	}
	int X = 0;
	int Y = 0;
	//printf("check2 - %d, %d\n", size, square2(size));
	
	X = startX;
	Y = startY;
	
	if(r <= X + square2(size) - 1 && c <= Y + square2(size) - 1)
	{
		//printf("check3-1 / X : %d, X + square2(size) - 1 : %d\n", X, X + square2(size) - 1);
		return checkQuadrant(size - 1, X, Y);
	}
	X = startX + square2(size);
	Y = startY;
	if(r <= X + square2(size) - 1 && c <= Y + square2(size) - 1)
	{
		//printf("check3-2\n");
		return (square2(size) * square2(size)) + checkQuadrant(size - 1, X, Y);
	}
	X = startX;
	Y = startY + square2(size);
	if(r <= X + square2(size) - 1 && c <= Y + square2(size) - 1)
	{
		//printf("check3-3\n");
		return 2 * (square2(size) * square2(size)) + checkQuadrant(size - 1, X, Y);
	}
	X = startX + square2(size);
	Y = startY + square2(size);
	if(r <= X + square2(size) - 1 && c <= Y + square2(size) - 1)
	{
		//printf("check3-4\n");
		return 3 * (square2(size) * square2(size)) + checkQuadrant(size - 1, X, Y);
	}
	printf("error\n");
	return -1;
}

int main(void)
{
	int n=0;
	
	scanf("%d %d %d",&n, &c, &r);
	printf("%d",checkQuadrant(n-1, 0, 0) );
	 
	
	return 0;
}
