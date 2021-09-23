//Number of question : 2630
//Difficulty : Silver 3
//Time to solve : 22m 32s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int paper[128][128] = {0};
int acountW=0;
int acountB=0;

void judgeColor(int firstX, int firstY, int size)
{
	int color=-1;
	for(int y=firstY; y<firstY+size; y++)
	{
		for(int x=firstX; x<firstX+size; x++)
		{
			if(color==-1)	color = paper[x][y];
			if(paper[x][y]!=color)
			{
				judgeColor(firstX, firstY,size/2);
 				judgeColor(firstX + size/2, firstY, size/2);
 				judgeColor(firstX, firstY + size/2, size/2);
 				judgeColor(firstX + size/2, firstY + size/2, size/2);
 				return;
			}
		}
	}
	if(color==0)	acountW++;
	else if(color==1)	acountB++;
	else	printf("error : color\n");
	
	return;
}
	
int main(void)
{	
	int n=0;
	
	scanf("%d",&n);
	for(int y=0 ; y<n ; y++)
	{
		for(int x=0 ; x<n ; x++)
		{
			scanf("%d",&paper[x][y]);
		}
	}
	judgeColor(0, 0, n);
	printf("%d\n%d",acountW, acountB);

	return 0;
}
