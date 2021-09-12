//Number of Question : 1541	
//Difficulty : Silver 2
//Time to solve : 30m 36s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int changeNum(char num)
{
	switch(num)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}


int main(void)
{
	char formula[300] = {'\0'};
	int num[50] = {0};
	int tempNum[5] = {0};
	int tempPos=0;
	int numPos=0;
	int changePos=1000;
	int sum=0;
	
	scanf("%s",formula);
	for(int i=0 ; i<=300 ; i++)
	{
		if(formula[i] == '+' || formula[i] == '-' || formula[i] == '\0')
		{
			//printf("check1\n");
			for(int j=0 ; j<=tempPos ; j++)
			{
				num[numPos] += tempNum[j] * (int)pow(10.0, (double)(tempPos-1-j));
			}
			numPos++;
			tempPos=0;
			if(changePos==1000 && formula[i]=='-')
			{
				changePos = numPos;
			}
			if(formula[i]=='\0')	break;
		}
		else
		{
			tempNum[tempPos] = changeNum(formula[i]);
			//printf("check2, %d¹øÂ° ¼ö : %d\n",tempPos+1, tempNum[tempPos]);
			tempPos++;
		}
	}
	for(int i=0 ; i<numPos ; i++)
	{
		//printf("%d ",num[i]);
		if(i<changePos)
		{
			sum+=num[i];
		}
		else
		{
			sum-=num[i];
		}
	}
	//printf("\n");
	printf("%d",sum);
	
	return 0;
}
