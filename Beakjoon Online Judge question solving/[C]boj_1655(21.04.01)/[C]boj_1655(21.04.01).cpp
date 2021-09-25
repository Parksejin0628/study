//number of question : 1655
//Difficulty : Gold 2
//Time to solve : 1h 40m 30s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int leftHeap[100100] = {0};
int rightHeap[100100] = {0};
int leftHeapAccount = 0;
int rightHeapAccount = 0;
int leftRearIndex = 1;
int rightRearIndex = 1;
int mid = 11111;

void addHeap(int num);
void addLeftHeap(int num);
void addRightHeap(int num);
void deleteLeftHeap();
void deleteRightHeap();

void addHeap(int num)
{
	if(mid == 11111)
	{
		mid = num;
		printf("%d\n",mid);
		return;
	}
	if(mid < num)	
	{
		rightHeapAccount++;
		addRightHeap(num);
	}
	else	
	{
		leftHeapAccount++;
		addLeftHeap(num);
	}
	if(leftHeapAccount > rightHeapAccount)
	{
		addRightHeap(mid);
		mid = leftHeap[1];
		deleteLeftHeap();
		leftHeapAccount --;
		rightHeapAccount ++;
	}
	else if(leftHeapAccount + 1 < rightHeapAccount)
	{
		addLeftHeap(mid);
		mid = rightHeap[1];
		deleteRightHeap();
		leftHeapAccount ++;
		rightHeapAccount --;
	}
	/*else
	{
		if(mid < num)	addRightHeap(num);
		else	addLeftHeap(num);
	}*/
	printf("%d\n",mid);
	return;
}

void addLeftHeap(int num)
{
	int parent = 0;
	int child = 0;
	
	leftHeap[leftRearIndex] = num;
	child = leftRearIndex++;
	parent = child / 2;
	
	while(child>1 && leftHeap[parent] < leftHeap[child])
	{
			leftHeap[child] = leftHeap[parent];
			leftHeap[parent] = num;
			child = parent;
			parent = child / 2;
	} 
}

void addRightHeap(int num)
{
	int parent = 0;
	int child = 0;
	
	rightHeap[rightRearIndex] = num;
	child = rightRearIndex++;
	//printf("rightRearIndex : %d\n",rightRearIndex);
	parent = child / 2;
	
	while(child>1 && rightHeap[parent] > rightHeap[child])
	{
			rightHeap[child] = rightHeap[parent];
			rightHeap[parent] = num;
			child = parent;
			parent = child / 2;
	} 
}

void deleteLeftHeap()
{
	int parent = 0;
	int child = 0;
	int temp = 0;
	
	leftHeap[1] = leftHeap[--leftRearIndex];
    if(leftRearIndex==1)    leftHeap[1] = 0;
	temp = leftHeap[1];
	parent = 1;
	child = parent * 2;
	
	if(child + 1 < leftRearIndex && leftHeap[child] < leftHeap[child + 1])
	{
		child = child + 1;
	}
	
	while(child < leftRearIndex && leftHeap[parent] < leftHeap[child])
	{
		leftHeap[parent] = leftHeap[child];
		leftHeap[child] = temp;
		parent = child;
		child = parent * 2;
		if(child + 1 < leftRearIndex && leftHeap[child] < leftHeap[child + 1])
		{
			child = child + 1;
		}
	}
}

void deleteRightHeap()
{
	int parent = 0;
	int child = 0;
	int temp = 0;
	
	rightHeap[1] = rightHeap[--rightRearIndex];
	//printf("rightHeap[1] = %d, rightRearIndex : %d\n",rightHeap[1], rightRearIndex);
    if(rightRearIndex==1)    rightHeap[1] = 0;
	temp = rightHeap[1];
	parent = 1;
	child = parent * 2;
	
	if(child + 1 < rightRearIndex && rightHeap[child] > rightHeap[child + 1])
	{
		child = child + 1;
	}
	
	while(child < rightRearIndex && rightHeap[parent] > rightHeap[child])
	{
		rightHeap[parent] = rightHeap[child];
		rightHeap[child] = temp;
		parent = child;
		child = parent * 2;
		if(child + 1 < rightRearIndex && rightHeap[child] > rightHeap[child + 1])
		{
			child = child + 1;
		}
	}
}

int main(void)
{
	int n = 0;
	int num = 0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&num);
		addHeap(num);
		//printf("left : %d, mid : %d, right : %d\n",leftHeap[1], mid, rightHeap[1]); 
	}
	
	return 0;
} 
