//number of question : 7662
//Difficulty : Gold 5
//Time to solve : 7h + @
//Simple review : 



/* 
알고리즘 : 이중 우선순위 큐를 최소힙, 최대힙을 동시에 이용하여 구현하였습니다.
기본 원리는 한쪽 힙에서 한 노드의 삭제연산이 일어나면, 반대쪽에 있는 같은 노드에도 삭제를 실행합니다.
노드의 정보를 담고있는 구조체 Data는 4개의 정보를 담고 있습니다.
1. value : 값
2. exist : 존재여부 /  값이 0인 경우 이미 삭제된 노드라고 판단합니다.
3. oppositePointer : 반대쪽 힙 배열의 시작주소
4. oppsiteIndex : 반대쪽 힙 배열에 있는 같은노드의 인덱스 값

함수의 경우 4개가 있습니다.
inqueue(long long value)
 - 값 입력, 최대힙과 최소힙에 새로운 원소를 추가합니다.
   그 후 최대힙, 최소힙을 정렬합니다. 
dequeue_max 
 - 최대힙의 첫번째 노드(최대값)를 제거합니다.
   그 후 최소힙에 있는 같은 노드의 exist값을 0으로 만듭니다. (삭제)
   만약 첫번째 노드의 exist값이 0이었다면, 삭제 연산을 한번 더 진행합니다. 
dequeue_min
 - 최소힙의 첫번째 노드를 제거합니다. 
   그 후 최대힙에 있는 노드의 exist값을 0으로 만듭니다. (삭제)
   만약 첫번째 노드의 exist값이 0이었다면, 삭제 연산을 한번 더 진행합니다.
   
   삭제 연산에서 반대편 힙에 있는 같은 노드를 탐색은 
   해당 노드의 oppositeIndex를 이용하여 O(1)만에 탐색합니다. 
changeIndex(data *queue, int index1, int index2)
 - 해당 힙(queue)의 노드 2 개의 위치를 바꿉니다.
   그 후 반대편 힙에 있는 같은 노드의 oppositeIndex값도 바꿔줍니다. 
   (노드의 위치가 바뀌었기 때문에) 
   
I연산에서는 inqueue함수를
D 1 연산에서는 dequeue_max함수를
D -1 연산에서는 dequeue_min함수를
힙 정렬 과정에서 노드의 위치를 바꿀 때는 changeIndex를 이용합니다.

모든 연산이 끝난 후에는 최대힙과 최소힙의 첫번째 노드의 exist값이 1이 될 때 까지
삭제연산을 반복합니다. 

그 후 최대힙과 최소힙의 첫번째 노드를 출력하여 최대값, 최소값을 출력합니다.
만약, 큐가 비어있을 경우에는 EMPTY를 출력하도록 합니다. 
*/


#include<stdio.h>
#include<string.h>
 
typedef struct Data
{
	long long value;
	int exist;
	struct Data *oppositePointer;
	int oppositeIndex;
}data;

void inqueue(long long value);
void dequeue_max();
void dequeue_min();
void changeIndex(data *queue, int index1, int index2);


data queue_max[1000100] = {};	//최대힙 
data queue_min[1000100] = {};	//최소힙 
data temp;						//changeIndex함수에서 사용하는 변수 
data *tempPointer;				//changeIndex함수에서 사용하는 변수 
data output;					//삭제연산에서 사용하는 변수로 삭제할 값을 저장한다. 

int top_max = 0;				//최대힙의 원소 개수 
int top_min = 0;				//최소힙의 원소 개수 
int pop = 1;					//pop이 0인 경우 삭제연산에서 exist값이 0인 원소만 삭제한다. 
int child = 0;					//자식노드 
int parent = 0;					//부모노드 
long long child_value = 0;		//자식노드의 value값 
long long parent_value = 0;		//부모노드의 value값 


int main(void)
{
	int testcase = 0;
	int k = 0;
	long long value = 0;
	char command;				//연산 
	
	scanf("%d",&testcase);
	for(int t=1; t<=testcase; t++)
	{
		scanf("%d",&k);
		fgetc(stdin);
		for(int i=0; i<k; i++)
		{
			scanf("%c", &command);
			if(command == 'I')
			{
				scanf("%lld",&value); //값 입력 
				fgetc(stdin);
				inqueue(value);
			}
			else if(command == 'D')
			{
				scanf("%lld",&value); // 1 또는 -1 입력 
				fgetc(stdin);
				if(value == 1 && top_max > 0)
				{
					dequeue_max();
				}
				else if(value == -1 && top_min > 0)
				{
					dequeue_min();
				}
			}
		}
		pop = 0; //최대힙과 최소힙 첫번째 요소의 exist값이 0인 것만 제거하기 위해 pop을 0으로 만든다. 
		while(queue_max[1].exist == 0) // 최대힙의 첫번째 요소의 exist값이 0인 경우 삭제연산 
		{
			dequeue_max();
			if(top_max == 0)	break;
		}
		while(queue_min[1].exist == 0) // 최소힙의 첫번째 요소의 exist값이 0인 경우 삭제연산 
		{
			dequeue_min();
			if(top_min == 0)	break;
		}
		if(top_max == 0 || top_min == 0)
		{
			printf("EMPTY\n");
		}
		else
		{
			printf("%lld %lld\n", queue_max[1].value, queue_min[1].value);
		}
		top_max = 0;
		top_min = 0;
		pop = 1;
	}
	scanf("%d",&k);
	
	return 0;
}

void inqueue(long long value)
{
	/*int child = 0;
	int parent = 0;
	long long child_value = 0;
	long long parent_value = 0;*/
	
	//value를 힙에 input 
	
	top_max++;
	top_min++;
	queue_max[top_max].value = value;
	queue_max[top_max].exist = 1;
	queue_max[top_max].oppositePointer = queue_min;
	queue_max[top_max].oppositeIndex = top_min;
	queue_min[top_min].value = value;
	queue_min[top_min].exist = 1;
	queue_min[top_min].oppositePointer = queue_max;
	queue_min[top_min].oppositeIndex = top_max;
	
	//최대힙 정렬  
	
	//printf("inqueue_max\n");
	child  = top_max;
	parent = child / 2;
	child_value = queue_max[child].value;
	parent_value = queue_max[parent].value;
	
	while(child_value > parent_value && parent > 0)
	{
		changeIndex(queue_max, parent, child);
		child = parent;
		parent = child / 2;
		child_value = queue_max[child].value;
		parent_value = queue_max[parent].value;
	}
	
	//최소힙 정렬  
	
	//printf("inqueue_min\n");
	child = top_min;
	parent = child / 2;
	child_value = queue_min[child].value;
	parent_value = queue_min[parent].value; 
	
	while(child_value < parent_value && parent > 0)
	{
		changeIndex(queue_min, parent, child);
		child = parent;
		parent = child / 2;
		child_value = queue_min[child].value;
		parent_value = queue_min[parent].value;
	}
	
	return;
}

void dequeue_max()
{
	/*data output = queue_max[1];
	int child = 0;
	int parent = 0;*/
	
	//printf("dequeue_max\n");
	while(1)
	{
		if(pop == 0 && queue_max[1].exist == 1)
		{
			return;
		}
		if(top_max < 1)
		{
			return;
		}
		output = queue_max[1];
		changeIndex(queue_max, 1, top_max);
		top_max--;
		parent = 1;
		child = parent * 2;
		if(child + 1 <= top_max && queue_max[child].value < queue_max[child+1].value)
		{
			child = child + 1;
		}
		while(queue_max[parent].value < queue_max[child].value && child <= top_max)
		{
			changeIndex(queue_max, parent, child);
			parent = child;
			child = parent * 2;
			if(child + 1 <= top_max && queue_max[child].value < queue_max[child+1].value)
			{
				child = child + 1;
			}
		}
		//첫번째 원소의 exist값이 1인 경우만 함수 종료
		//즉, 삭제해야할 원소가 이미 삭제된 값인 경우 (exist값이 0인 경우) 삭제연산을 반복한다. 
		if(output.exist == 1)  
		{
			output.exist = 0;
			output.oppositePointer[output.oppositeIndex].exist = 0;
			return;
		}
	}
}

void dequeue_min()
{
	/*data output = queue_min[1];
	int child = 0;
	int parent = 0;*/
	
	//printf("dequeue_min\n");
	while(1)
	{
		if(pop == 0 && queue_min[1].exist == 1)
		{
			return;
		}
		if(top_min == 0)
		{
			return;
		}
		output = queue_min[1];
		changeIndex(queue_min, 1, top_min);
		top_min--;
		parent = 1;
		child = parent * 2;
		if(child + 1 <= top_min && queue_min[child].value > queue_min[child+1].value)
		{
			child = child + 1;
		}
		while(queue_min[parent].value > queue_min[child].value && child <= top_min)
		{
			changeIndex(queue_min, parent, child);
			parent = child;
			child = parent * 2;
			if(child + 1 <= top_min && queue_min[child].value > queue_min[child+1].value)
			{
				child = child + 1;
			}
		}
		if(output.exist == 1)
		{
			output.exist = 0;
			output.oppositePointer[output.oppositeIndex].exist = 0;
			return;
		}
	}
}

//*queue는 현재 노드의 위치를 바꾸는 힙이 최대힙인지, 최소힙인지 판단하기 위한 포인터 
void changeIndex(data *queue, int index1, int index2)
{
	if(queue[index1].oppositeIndex == 0 || queue[index2].oppositeIndex == 0)
	{
		//printf("error\n");
		return;
	}

	//위치변환 
	temp = queue[index1];
	queue[index1] = queue[index2];
	queue[index2] = temp;
	
	//반대편 노드에 바뀐 위치를 저장 
	tempPointer = queue[index1].oppositePointer;
	tempPointer[queue[index1].oppositeIndex].oppositeIndex = index1;
	tempPointer = queue[index2].oppositePointer;
	tempPointer[queue[index2].oppositeIndex].oppositeIndex = index2;
	//printf("1_현재 인덱스 : %d, 현재 값 : %lld, 반대편 값 : %lld, 반대편 인덱스 값 : %d\n", index1, queue[index1].value, queue[index1].oppositePointer[queue[index1].oppositeIndex].value, queue[index1].oppositePointer[queue[index1].oppositeIndex].oppositeIndex);
	//printf("2_현재 인덱스 : %d, 현재 값 : %lld, 반대편 값 : %lld, 반대편 인덱스 값 : %d\n", index2, queue[index2].value, queue[index2].oppositePointer[queue[index2].oppositeIndex].value, queue[index2].oppositePointer[queue[index2].oppositeIndex].oppositeIndex);
	
	return;
}
