//number of question : 2493
//Difficulty : Gold 5
//Time to solve : 29m 5s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int stack[600000][2] = {0};

int main(void)
{
	int n = 0;
	int top = -1;
	int temp = 0;
	//int num = 0;
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&temp);
		//printf("check1 i : %d\n", i);
		for(int j=top; j>=0; j--)
		{
			//printf("¿¬»êÈ½¼ö : %d\n",++num);
			if(stack[j][0] < temp)
			{
				top--;
			}
			else
			{
				printf("%d ",stack[j][1]);
				stack[++top][0] = temp;
				stack[top][1] = i;
				break;
			}
		}
		if(top == -1)
		{
			printf("0 ");
			stack[++top][0] = temp;
			stack[top][1] = i;
		}
	}
	//scanf("%d",&n); 
	
	return 0;
}
