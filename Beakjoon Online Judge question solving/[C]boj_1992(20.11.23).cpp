//Number of question : 1992
//Difficulty : Silver 1
//Time to solve : 28m 6s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int paper[64][64] = {0};

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
				printf("(");
				judgeColor(firstX, firstY,size/2);
 				judgeColor(firstX + size/2, firstY, size/2);
 				judgeColor(firstX, firstY + size/2, size/2);
 				judgeColor(firstX + size/2, firstY + size/2, size/2);
 				printf(")");
 				return;
			}
		}
	}
	printf("%d",color);
	
	return;
}
	
int main(void)
{	
	int n=0;
	char temp[70]={'\0'};
	
	scanf("%d",&n);
	fgetc(stdin);
	for(int y=0 ; y<n ; y++) 
	{
		fgets(temp,70,stdin);
		for(int x=0 ; x<n ; x++)
		{
			if(temp[x]=='1')	paper[x][y] = 1;
			else	paper[x][y] = 0;
		}
	}
	/*for(int y=0 ; y<n ; y++)
	{
		for(int x=0 ; x<n ; x++)
		{
			printf("%d ",paper[x][y]);
		}
		printf("\n");
	}*/
	judgeColor(0, 0, n);

	return 0;
}
