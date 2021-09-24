//number of question : 11279
//Difficulty : Silver 2
//Time to solve : 1h 32m 54s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int upHeap[100100] = {0};
int rear = 1;
int tempIndex = 0; 

void addHeap(int num);
void deleteHeap();

void addHeap(int num)
{
	upHeap[rear] = num;
	tempIndex = rear;
	while(tempIndex > 1 && upHeap[tempIndex/2] < num)
	{
		upHeap[tempIndex] = upHeap[tempIndex/2];
		upHeap[tempIndex/2] = num;
		tempIndex /=2;
	}
	rear++;
}

void deleteHeap()
{
	int temp = 0;
	int sel = 0;
	
	if(rear == 1)
	{
		printf("0\n");
		return;
	}
	printf("%d\n",upHeap[1]);
	upHeap[1] = upHeap[--rear];
	upHeap[rear] = 0;
	temp = upHeap[1];
	tempIndex = 1;
	while(tempIndex*2<=rear)
	{
		sel = 0;
		if(upHeap[tempIndex*2] >= temp && upHeap[tempIndex*2+1] >= temp)
		{
			if(upHeap[tempIndex*2] <= upHeap[tempIndex*2+1])
			{
				sel = 1;
			}
		}
		if(upHeap[tempIndex*2] >= temp && sel!=1)
		{
			upHeap[tempIndex] = upHeap[tempIndex*2];
			upHeap[tempIndex*2] = temp;
			tempIndex = tempIndex * 2;
			continue;
		}
		else if(upHeap[tempIndex*2+1] >= temp)
		{
			upHeap[tempIndex] = upHeap[tempIndex*2+1];
			upHeap[tempIndex*2+1] = temp;
			tempIndex = tempIndex * 2 + 1;
			continue;
		}
		break;
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
		/*printf("현재 정렬 상태 : ");
		for(int j=1; j<=rear+10; j++)
		{
			printf("%d ",upHeap[j]);
		}
		printf("\n");*/
		 
	} 
	
	return 0;
}
