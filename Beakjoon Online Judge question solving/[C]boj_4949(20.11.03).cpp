//Number of Question : 4949
//Difficulty : Silver 4
//Time to solve : 30m 25s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{	
	char temp[110] = {'\0'};
	char parenthesis[110] = {'\0'};
	int acount=0;
	
	while(1)
	{
		fgets(temp, 110, stdin);
		if(temp[0]=='.' && temp[1]=='\n')	break;
		for(int i=0 ; temp[i]!='\0' ; i++)
		{
			if(temp[i] == '(')
			{
				parenthesis[acount] = '('; 
				acount++;
			}
			else if(temp[i] == '[')
			{
				parenthesis[acount] = '[';
				acount++;
			}
			else if(temp[i] == ')')
			{
				if(acount-1 <0 || parenthesis[acount-1]!='(')
				{
					acount=-1;
					break;
				}
				parenthesis[acount-1] = '\0';
				acount--;
			}
			else if(temp[i] == ']')
			{
				if(acount-1 <0 || parenthesis[acount-1]!='[')
				{
					acount=-1;
					break;
				}
				parenthesis[acount-1] = '\0';
				acount--;
			}
			//printf("%d : acount - %d\n",i+1,acount);
		}
		if(acount==0)	printf("yes\n");
		else	printf("no\n");
		for(int i=0 ; i<acount ; i++)
		{
			parenthesis[i] = '\0';
		}
		acount=0;
	}
	
	return 0;
}
