//Number of Question : 9012
//Difficulty : Silver 4
//Time to solve : 7m 53s
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
	char temp[60] = {'\0'};
	int acount=0;
	
	scanf("%d",&t);
	for(int i=0 ; i<t ; i++)
	{
		scanf("%s",temp);
		for(int i=0 ; temp[i]!='\0' ; i++)
		{
			if(temp[i]=='(')	acount++;
			else if(temp[i]==')')	acount--;	
			if(acount<0)	break;
		}
		if(acount==0)	printf("YES\n");
		else	printf("NO\n");
		acount=0;
		strcpy(temp,"\0");
	}
	
	return 0;
}
