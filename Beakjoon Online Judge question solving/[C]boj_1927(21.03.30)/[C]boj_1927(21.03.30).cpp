//number of question : 1927
//Difficulty : Silver 1
//Time to solve : 37m 44s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int downHeap[100100] = {0};
int rear = 1;

void addHeap(int num);
void deleteHeap();

void addHeap(int num)
{
	int tempIndex = rear;
	
	downHeap[rear] = num;
	rear++;
	
	while(downHeap[tempIndex] <= downHeap[tempIndex/2] && tempIndex>1 && downHeap[tempIndex/2] !=0)
	{
		downHeap[tempIndex] = downHeap[tempIndex/2];
		downHeap[tempIndex/2] = num;
		tempIndex = tempIndex/2;
	}
}

void deleteHeap()
{
	if(rear==1)
	{
		printf("0\n");
		return;
	}
	int tempIndex = 1;
	int temp = 0;
	
	printf("%d\n",downHeap[1]);
	downHeap[1] = downHeap[--rear];
	downHeap[rear] = 0;
	temp = downHeap[1];
	
	while(tempIndex*2 <= rear)
	{
		if(downHeap[tempIndex*2] <= downHeap[tempIndex] && downHeap[tempIndex*2+1] <= downHeap[tempIndex] && downHeap[tempIndex*2]!=0 && downHeap[tempIndex*2+1]!=0)
		{
			if(downHeap[tempIndex*2] <= downHeap[tempIndex*2+1])
			{
				downHeap[tempIndex] = downHeap[tempIndex*2];
				downHeap[tempIndex*2] =  temp;
				tempIndex = tempIndex * 2;
			}
			else
			{
				downHeap[tempIndex] = downHeap[tempIndex*2+1];
				downHeap[tempIndex*2+1] =  temp;
				tempIndex = tempIndex * 2 + 1;
			}
			continue;
		}
		else if(downHeap[tempIndex*2] <= downHeap[tempIndex] && downHeap[tempIndex*2]!=0)
		{
			downHeap[tempIndex] = downHeap[tempIndex*2];
			downHeap[tempIndex*2] =  temp;
			tempIndex = tempIndex * 2;
			continue;
		}
		else if(downHeap[tempIndex*2+1] <= downHeap[tempIndex] && downHeap[tempIndex*2+1]!=0)
		{
			downHeap[tempIndex] = downHeap[tempIndex*2+1];
			downHeap[tempIndex*2+1] =  temp;
			tempIndex = tempIndex * 2 + 1;
			continue;
		}
		else
		{
			break;
		}
	}
	
}

int main(void)
{
	int n=0;
	int x=0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		if(x==0)	deleteHeap();
		else	addHeap(x);
	/*	printf("현재 정렬 : ");
		for(int j=1; j<=rear; j++)
		{
			printf("%d ",downHeap[j]);
		}
		printf("\n");*/
	}
	
	return 0;
}
