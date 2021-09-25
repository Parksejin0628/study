//number of question : 1158
//Difficulty : Silver 5
//Time to solve : 18m 41s
//Simple review : 

#include<stdio.h>

int queue[6000] = {0};

int main(void)
{
	int n = 0;
	int k = 0;
	int num = 0;
	int frontIndex = -1;
	int rearIndex = -1;
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		queue[++rearIndex] = i;
	}
	scanf("%d",&k);
	printf("<");
	while((frontIndex)%6000!=(rearIndex)%6000)
	{
		num++;
		if(num==k)
		{
			printf("%d",queue[(++frontIndex)%6000]);
			num = 0;
			if((frontIndex)%6000==(rearIndex)%6000)
			{
				printf(">");
			}
			else
			{
				printf(", ");
			}
			continue;
		}
		queue[(++rearIndex)%6000] = queue[(++frontIndex)%6000];  
	}
	scanf("%d",&n);
	
	return 0;
}
