//Number of Question : 9251
//Difficulty : Gold 5
//Time to solve : 5h 27m 45s
//Simple review : LCS.. need study more

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

char seq[2][1010] = {'\0'};
int optimalSum[1010][1010]={0};

int main(void)
{
	
	int max=0;
	
	scanf("%s",seq[0]);
	scanf("%s",seq[1]);
	
	for(int i=0 ; i<=1000 ; i++)
	{
		//printf("check1\n");
		if(seq[0][i] == '\0')	break;
		for(int j=0 ; j<=1000 ; j++)
		{
			//printf("check2\n");
			if(seq[1][j] == '\0')	break;
			optimalSum[i+1][j+1]=(optimalSum[i][j+1]>optimalSum[i+1][j]) ? optimalSum[i][j+1] : optimalSum[i+1][j];
			if(seq[0][i] == seq[1][j])	optimalSum[i+1][j+1]=optimalSum[i][j]+1;
			if(optimalSum[i+1][j+1]>max)	max=optimalSum[i+1][j+1];
			//printf("%d,%d : %d\n",i,j,optimalSum[i+1][j+1]);
		}
	}
	
	printf("%d",max);
	
	
	
	return 0;
}
