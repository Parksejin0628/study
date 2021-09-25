//number of question : 1259
//Difficulty : Bronze 1
//Time to solve : 17m 36s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void)
{
	int length = 0;
	char num[100] = {'\0'};
	
	while(strcmp(num, "0")!=0)
	{
		fgets(num, 90, stdin);
		if(num[0] == '0')	break;
		for(int i=0; i<=90; i++)
		{
			if(num[i]=='\n')
			{
				length = i-1;
			//	printf("check2 - length : %d\n",length);
				break;
			}
		}
		for(int i=0; i<=90; i++)
		{
			if(i>=length-i)
			{
				printf("yes\n");
				break;
			}
			if(num[i]!=num[length-i])
			{
			//	printf("i : %d, length-i : %d, %c, %c\n",i, length-i, num[i], num[length-i]);
				printf("no\n");
				break;
			}
		}
		length = 0;
		//printf("check1\n");
	}
	
	return 0;
} 
