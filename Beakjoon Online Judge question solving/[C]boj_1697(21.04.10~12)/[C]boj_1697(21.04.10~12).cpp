//number of question : 1697
//Difficulty : Silver 1
//Time to solve : 2h 9m 7s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int quque[1000100][2] = {0}; 
int checkBFS[300100] = {0};
int complexity = 0;

int closer(int num1, int num2, int criteria)
{
	int temp1 = criteria - num1;
	int temp2 = criteria - num2;
	if(temp1<0)	temp1 *= -1;
	if(temp2<0) temp2 *= -1;
	
	if(temp1 <= temp2)	return 0;
	return 1;
}

int main(void)
{
	int n=0;
	int k=0;
	int level = 0;
	int nextLevel = 1;
	int rearIndex[2] = {0};
	int time = 0;
	
	scanf("%d %d",&n, &k);
	quque[0][level] = n;
	rearIndex[level] = 1;
	while(true)
	{
		time++;
		rearIndex[level]--;
		for(int i=0 ; i<=rearIndex[level]; i++)
		{
			//printf("check1(%d) - level : %d, index : %d, num : %d, time : %d\n", complexity++, level, i, quque[i][level],time);
			if(quque[i][level] == k)
			{
				printf("%d\n",time-1);
				//scanf("%d",&n);
				return 0;
			}
			if(quque[i][level]*2 == k || quque[i][level]+1 == k || quque[i][level]-1 == k)
			{
				printf("%d\n",time);
				//scanf("%d",&n);
				return 0;
			}
			checkBFS[quque[i][level]] = 1;
			if(checkBFS[quque[i][level]+1] == 0 && quque[i][level]+1 < k)
			{
				quque[rearIndex[nextLevel]++][nextLevel] = quque[i][level] + 1;
			}
			if(checkBFS[quque[i][level]-1] == 0 && quque[i][level]-1 >= 0)
			{
				quque[rearIndex[nextLevel]++][nextLevel] = quque[i][level] - 1;
			}
			if(checkBFS[quque[i][level]*2] == 0 && closer(quque[i][level]*2, quque[i][level], k) == 0)
			{
				quque[rearIndex[nextLevel]++][nextLevel] = quque[i][level] * 2;
			}
		}
		rearIndex[level] = 0;
		if(level == 0)
		{
			level = 1;
			nextLevel =0;
		}
		else
		{
			level = 0;
			nextLevel = 1;
		}
	}
	
	
	return 0;
}
