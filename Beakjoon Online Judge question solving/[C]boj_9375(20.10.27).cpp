//Number of Question : 9375
//Difficulty : Silver 3
//Time to solve : 40m 15s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int t=0;
	int n=0;
	int temp=0;
	int kindNum=0;
	int kindAcount[40]={0};
	int caseNum=1;
	char tempName[30] = {'\0'};
	char tempKind[30] = {'\0'};
	char kind[40][40] = {'\0'};
	
	scanf("%d", &t);
	for(int i=0 ; i<t ; i++)
	{
		scanf("%d", &n);
		for(int j=0 ; j<n ; j++)
		{
			scanf("%s %s",tempName, tempKind);
			for(int k=0 ; k<kindNum ; k++)
			{
				if(strcmp(kind[k], tempKind)==0)
				{
					kindAcount[k]++;
					strcpy(kind[k], tempKind);
					temp=1;
				}
			}
			if(!temp)
			{
				strcpy(kind[kindNum], tempKind);
				kindAcount[kindNum]++;
				kindNum++;
			}
			temp=0;
		}
		//printf("kindNum : %d\n",kindNum);
		for(int j=0 ; j<kindNum ; j++)
		{
			//printf("%d¹øÂ° kindAcount : %d\n",j, kindAcount[j]);
			caseNum *= kindAcount[j]+1;
		}
		printf("%d\n",caseNum-1);
		caseNum=1;
		kindNum=0;
		for(int j=0 ; j<40 ; j++)
		{
			kindAcount[j]=0;
			strcpy(kind[j],"\0");
		}
		//printf("check2\n");
	}
	
	
	return 0;
}
