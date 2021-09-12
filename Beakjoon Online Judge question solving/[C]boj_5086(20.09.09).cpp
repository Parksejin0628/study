//Number of Question : 5086
//Difficulty : Bronze 3
//Time to solve : 3m 28s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int main(void)
{
	int num1=-1;
	int num2=-1;
	while(true)
	{
		scanf("%d %d",&num1,&num2);
		if(num1==0 && num2==0)	break;
		if(num1<=num2 && num2%num1==0)	printf("factor\n");
		else if(num1>=num2 && num1%num2==0)	printf("multiple\n");
		else	printf("neither\n");
	}
	
	return 0;
}
