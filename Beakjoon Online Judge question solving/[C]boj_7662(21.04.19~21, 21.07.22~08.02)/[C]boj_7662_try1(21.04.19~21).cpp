//number of question : 7662
//Difficulty : Gold5
//Time to solve : 2h 1m 19s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int minQueue[1000100] = {0};
int maxQueue[1000100] = {0};
int minRearIndex = 1;
int maxRearIndex = 1;
int invalidMinQueue[1000100] = {0};
int invalidMaxQueue[1000100] = {0};
int count = 0;
int invalidMaxIndex = 0;
int invalidMinIndex = 0;

void inputMaxQueue(int num);
void inputMinQueue(int num);
void deleteMaxQueue();
void deleteMinQueue();
void removeInvalidMaxQueue();
void removeInvalidMinQueue();

void inputMaxQueue(int num)
{
	int parent = 0;
	int child = maxRearIndex;
	int temp = 0;
	
	//printf("check1\n");
	maxQueue[maxRearIndex++] = num;
	parent = child / 2;
	while(maxQueue[parent] < maxQueue[child])
	{
		//printf("check1-1\n");
		temp = maxQueue[parent];
		maxQueue[parent] = maxQueue[child];
		maxQueue[child] = temp;
		child = parent;
		parent = child / 2;
	}
	
	return;
}

void inputMinQueue(int num)
{
	int parent = 0;
	int child = minRearIndex;
	int temp = 0;
	
	//printf("check2\n");
	minQueue[minRearIndex++] = num;
	parent = child / 2;
	while(minQueue[parent] > minQueue[child])
	{
		temp = minQueue[parent];
		minQueue[parent] = minQueue[child];
		minQueue[child] = temp;
		child = parent;
		parent = child / 2;
	}
	
	return;
}

void deleteMaxQueue()
{
	int parent = 1;
	int child = parent * 2;
	int temp = 0;
	int top = 0;
	
	//printf("check3\n");
	removeInvalidMaxQueue();
	top = maxQueue[1];
	maxQueue[1] = maxQueue[maxRearIndex--];
	if(child + 1 < maxRearIndex && maxQueue[child + 1] > maxQueue[child])
	{
		child = child + 1;
	}
	while(maxQueue[child] >= maxQueue[parent] && child < maxRearIndex)
	{
		temp = maxQueue[child];
		maxQueue[child] = maxQueue[parent];
		maxQueue[parent] = temp;
		parent = child;
		child = parent * 2;
		if(child + 1 < maxRearIndex && maxQueue[child + 1] > maxQueue[child])
		{
		child = child + 1;
		}
	}
	invalidMinQueue[invalidMinIndex++] = top;
	count --;
} 

void deleteMinQueue()
{
	int parent = 1;
	int child = parent * 2;
	int temp = 0;
	int top = 0;
	
	//printf("check4\n");
	removeInvalidMinQueue();
	top = minQueue[1];
	minQueue[1] = minQueue[minRearIndex--];
	if(child + 1 < minRearIndex && minQueue[child + 1] < minQueue[child])
	{
		child = child + 1;
	}
	while(minQueue[child] <= minQueue[parent] && child < minRearIndex)
	{
		temp = minQueue[child];
		minQueue[child] = minQueue[parent];
		minQueue[parent] = temp;
		parent = child;
		child = parent * 2;
		if(child + 1 < minRearIndex && minQueue[child + 1] < minQueue[child])
		{
		child = child + 1;
		}
	}
	invalidMaxQueue[invalidMaxIndex++] = top;
	count --;
} 

void removeInvalidMaxQueue()
{
	int parent = 1;
	int child = parent * 2;
	int top = maxQueue[1];
	int remove = 0;
	int temp = 0;
	
	//printf("check5\n");
	while(true)
	{
		top = maxQueue[1];
		parent = 1;
		child = parent * 2;
		remove = 0;
		for(int i=0; i<invalidMaxIndex; i++)
		{
			if(top == invalidMaxQueue[i])
			{
				remove = 1;
				invalidMaxQueue[i] = 0;
				maxQueue[1] = maxQueue[minRearIndex--];
				if(child + 1 < maxRearIndex && maxQueue[child + 1] > maxQueue[child])
				{
					child = child + 1;
				}
				while(maxQueue[child] >= maxQueue[parent] && child < maxRearIndex)
				{
					temp = minQueue[child];
					maxQueue[child] = maxQueue[parent];
					maxQueue[parent] = temp;
					parent = child;
					child = parent * 2;
					if(child + 1 < maxRearIndex && maxQueue[child + 1] > maxQueue[child])
					{
						child = child + 1;
					}
				}
				break;
			}
		}
		if(remove == 0)	break;
	}
}

void removeInvalidMinQueue()
{
	int parent = 1;
	int child = parent * 2;
	int top = minQueue[1];
	int remove = 0;
	int temp = 0;
	
	//printf("check6\n");
	while(true)
	{
		//printf("check6-1\n");
		top = minQueue[1];
		parent = 1;
		child = parent * 2;
		remove = 0;
		for(int i=0; i<invalidMinIndex; i++)
		{
			if(top == invalidMinQueue[i])
			{
				remove = 1;
				invalidMinQueue[i] = 0;
				minQueue[1] = minQueue[minRearIndex--];
				if(child + 1 < minRearIndex && minQueue[child + 1] < minQueue[child])
				{
					child = child + 1;
				}
				while(minQueue[child] <= minQueue[parent] && child < minRearIndex)
				{
					temp = minQueue[child];
					minQueue[child] = minQueue[parent];
					minQueue[parent] = temp;
					parent = child;
					child = parent * 2;
					if(child + 1 < minRearIndex && minQueue[child + 1] < minQueue[child])
					{
						child = child + 1;
					}
				}
				break;
			}
		}
		if(remove == 0)	break;
	}
}


int main(void)
{
	int testcase = 0;
	char command[10] = {'\0'};
	int num = 0;
	int k = 0; 
	
	scanf("%d",&testcase);
	for(int t=0; t<testcase; t++)
	{
		scanf("%d",&k);
		fgetc(stdin);
		for(int i=0; i<k; i++)
		{ 
			scanf("%s",command);
			//printf("check7 i : %d\n",i);
			//printf("check8 command : %s\n",command);
			if(strcmp(command, "I") == 0)
			{
				scanf("%d",&num);
				inputMaxQueue(num);
				inputMinQueue(num);
				count ++;
			}
			else if(strcmp(command, "D") == 0)
			{
				scanf("%d",&num);
				if(count <= 0)	continue;
				if(num > 0)
				{
					deleteMaxQueue();
				}
				else
				{
					deleteMinQueue();
				}
			}
			//printf("check9 - count : %d\n", count);
		}
		if(count <= 0)	printf("EMPTY\n");
		else
		{
			removeInvalidMaxQueue();
			removeInvalidMinQueue();
			printf("%d %d", maxQueue[1], minQueue[1]);
		}
		count = 0;
		minRearIndex = 1;
		maxRearIndex = 1;
		invalidMaxIndex = 0;
		invalidMinIndex = 0;
	}
//	scanf("%d",&k);
	
	return 0;
}
