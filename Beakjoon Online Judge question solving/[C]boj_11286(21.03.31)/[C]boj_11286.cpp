//number of question : 11286
//Difficulty : Silver 1
//Time to solve : 40m 18s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int absoluteDownHeap[100100] = {0};
int rearIndex = 1;

void addHeap(int num);
void deleteHeap();
void swap(int num1, int num2);
int compareAbsolute(int num1, int num2);

void addHeap(int num)
{
	int child = 0;
	int parent = 0;
	
	absoluteDownHeap[rearIndex] = num;
	child = rearIndex;
	parent = child / 2;
	rearIndex++;
	
	while(child > 1 && compareAbsolute(child, parent))
	{
		swap(child, parent);
		child = parent;
		parent = child / 2;
	}
}

void deleteHeap()
{
	//printf("Ãâ·Â : ");
	if(rearIndex <= 1)
	{
		printf("0\n");
		return;
	}
	
	int child = 0;
	int parent = 0;
	
	printf("%d\n", absoluteDownHeap[1]);
	swap(1, --rearIndex);
	parent = 1;
	child = parent * 2;
	if(child + 1 < rearIndex && compareAbsolute(child + 1, child))
	{
		child = child + 1;
	}
	while(child < rearIndex && compareAbsolute(child, parent))
	{
		swap(parent, child);
		parent = child;
		child = parent * 2;
		if(child + 1 < rearIndex && compareAbsolute(child + 1, child))
		{
			child = child + 1;
		}
	}
}

int compareAbsolute(int num1, int num2)
{
	if(absoluteDownHeap[num1] == 0 || absoluteDownHeap[num2] == 0)
	{
		return 0;
	}
	
	int num1Ab = absoluteDownHeap[num1];
	int num2Ab = absoluteDownHeap[num2];
	
	if(num1Ab < 0)	num1Ab *= -1;
	if(num2Ab < 0)  num2Ab *= -1;
	
	if(num1Ab == num2Ab)
	{
		if(absoluteDownHeap[num1] < 0)
		{
			return 1;
		}
		else	return 0;
	}
	else
	{
		if(num1Ab < num2Ab)	return 1;
		else	return 0;
	}
}

void swap(int num1, int num2)
{
	int temp = absoluteDownHeap[num1];
	absoluteDownHeap[num1] = absoluteDownHeap[num2];
	absoluteDownHeap[num2] = temp;
}

int main(void)
{
	int n = 0;
	int x = 0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		if(x==0)	deleteHeap();
		else	addHeap(x);
	}
	
	return 0;
}
