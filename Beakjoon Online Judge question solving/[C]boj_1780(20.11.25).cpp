//Number of question : 1780
//Difficulty : Silver 2
//Time to solve : 17m 26s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int paper[2187][2187] = {0};
int acount[3] = {0};

void judgeColor(int firstX, int firstY, int size)
{
	int color = 2;
	//printf("check1 : %d %d %d\n",firstX, firstY, size);
	for(int y=firstY ; y<firstY + size ; y++)
	{
		for(int x=firstX ; x<firstX + size ; x++)
		{
			if(color==2)	color = paper[x][y];
			else if(color != paper[x][y])
			{
				judgeColor(firstX, firstY, size/3);
				judgeColor(firstX + size/3, firstY, size/3);
				judgeColor(firstX + 2*size/3, firstY, size/3);
				judgeColor(firstX, firstY + size/3, size/3);
				judgeColor(firstX + size/3, firstY + size/3, size/3);
				judgeColor(firstX + 2*size/3, firstY + size/3, size/3);
				judgeColor(firstX, firstY + 2*size/3, size/3);
				judgeColor(firstX + size/3, firstY + 2*size/3, size/3);
				judgeColor(firstX + 2*size/3, firstY + 2*size/3, size/3);
				return;
			}
		}
	}
	acount[color+1]++;
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
	for(int i=0 ; i<3 ; i++)
		printf("%d\n",acount[i]);

	return 0;
}
