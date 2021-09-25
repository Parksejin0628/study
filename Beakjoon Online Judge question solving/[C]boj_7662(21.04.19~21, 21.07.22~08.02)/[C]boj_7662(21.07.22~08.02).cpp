//number of question : 7662
//Difficulty : Gold 5
//Time to solve : 7h + @
//Simple review : 



/* 
�˰��� : ���� �켱���� ť�� �ּ���, �ִ����� ���ÿ� �̿��Ͽ� �����Ͽ����ϴ�.
�⺻ ������ ���� ������ �� ����� ���������� �Ͼ��, �ݴ��ʿ� �ִ� ���� ��忡�� ������ �����մϴ�.
����� ������ ����ִ� ����ü Data�� 4���� ������ ��� �ֽ��ϴ�.
1. value : ��
2. exist : ���翩�� /  ���� 0�� ��� �̹� ������ ����� �Ǵ��մϴ�.
3. oppositePointer : �ݴ��� �� �迭�� �����ּ�
4. oppsiteIndex : �ݴ��� �� �迭�� �ִ� ��������� �ε��� ��

�Լ��� ��� 4���� �ֽ��ϴ�.
inqueue(long long value)
 - �� �Է�, �ִ����� �ּ����� ���ο� ���Ҹ� �߰��մϴ�.
   �� �� �ִ���, �ּ����� �����մϴ�. 
dequeue_max 
 - �ִ����� ù��° ���(�ִ밪)�� �����մϴ�.
   �� �� �ּ����� �ִ� ���� ����� exist���� 0���� ����ϴ�. (����)
   ���� ù��° ����� exist���� 0�̾��ٸ�, ���� ������ �ѹ� �� �����մϴ�. 
dequeue_min
 - �ּ����� ù��° ��带 �����մϴ�. 
   �� �� �ִ����� �ִ� ����� exist���� 0���� ����ϴ�. (����)
   ���� ù��° ����� exist���� 0�̾��ٸ�, ���� ������ �ѹ� �� �����մϴ�.
   
   ���� ���꿡�� �ݴ��� ���� �ִ� ���� ��带 Ž���� 
   �ش� ����� oppositeIndex�� �̿��Ͽ� O(1)���� Ž���մϴ�. 
changeIndex(data *queue, int index1, int index2)
 - �ش� ��(queue)�� ��� 2 ���� ��ġ�� �ٲߴϴ�.
   �� �� �ݴ��� ���� �ִ� ���� ����� oppositeIndex���� �ٲ��ݴϴ�. 
   (����� ��ġ�� �ٲ���� ������) 
   
I���꿡���� inqueue�Լ���
D 1 ���꿡���� dequeue_max�Լ���
D -1 ���꿡���� dequeue_min�Լ���
�� ���� �������� ����� ��ġ�� �ٲ� ���� changeIndex�� �̿��մϴ�.

��� ������ ���� �Ŀ��� �ִ����� �ּ����� ù��° ����� exist���� 1�� �� �� ����
���������� �ݺ��մϴ�. 

�� �� �ִ����� �ּ����� ù��° ��带 ����Ͽ� �ִ밪, �ּҰ��� ����մϴ�.
����, ť�� ������� ��쿡�� EMPTY�� ����ϵ��� �մϴ�. 
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


data queue_max[1000100] = {};	//�ִ��� 
data queue_min[1000100] = {};	//�ּ��� 
data temp;						//changeIndex�Լ����� ����ϴ� ���� 
data *tempPointer;				//changeIndex�Լ����� ����ϴ� ���� 
data output;					//�������꿡�� ����ϴ� ������ ������ ���� �����Ѵ�. 

int top_max = 0;				//�ִ����� ���� ���� 
int top_min = 0;				//�ּ����� ���� ���� 
int pop = 1;					//pop�� 0�� ��� �������꿡�� exist���� 0�� ���Ҹ� �����Ѵ�. 
int child = 0;					//�ڽĳ�� 
int parent = 0;					//�θ��� 
long long child_value = 0;		//�ڽĳ���� value�� 
long long parent_value = 0;		//�θ����� value�� 


int main(void)
{
	int testcase = 0;
	int k = 0;
	long long value = 0;
	char command;				//���� 
	
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
				scanf("%lld",&value); //�� �Է� 
				fgetc(stdin);
				inqueue(value);
			}
			else if(command == 'D')
			{
				scanf("%lld",&value); // 1 �Ǵ� -1 �Է� 
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
		pop = 0; //�ִ����� �ּ��� ù��° ����� exist���� 0�� �͸� �����ϱ� ���� pop�� 0���� �����. 
		while(queue_max[1].exist == 0) // �ִ����� ù��° ����� exist���� 0�� ��� �������� 
		{
			dequeue_max();
			if(top_max == 0)	break;
		}
		while(queue_min[1].exist == 0) // �ּ����� ù��° ����� exist���� 0�� ��� �������� 
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
	
	//value�� ���� input 
	
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
	
	//�ִ��� ����  
	
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
	
	//�ּ��� ����  
	
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
		//ù��° ������ exist���� 1�� ��츸 �Լ� ����
		//��, �����ؾ��� ���Ұ� �̹� ������ ���� ��� (exist���� 0�� ���) ���������� �ݺ��Ѵ�. 
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

//*queue�� ���� ����� ��ġ�� �ٲٴ� ���� �ִ�������, �ּ������� �Ǵ��ϱ� ���� ������ 
void changeIndex(data *queue, int index1, int index2)
{
	if(queue[index1].oppositeIndex == 0 || queue[index2].oppositeIndex == 0)
	{
		//printf("error\n");
		return;
	}

	//��ġ��ȯ 
	temp = queue[index1];
	queue[index1] = queue[index2];
	queue[index2] = temp;
	
	//�ݴ��� ��忡 �ٲ� ��ġ�� ���� 
	tempPointer = queue[index1].oppositePointer;
	tempPointer[queue[index1].oppositeIndex].oppositeIndex = index1;
	tempPointer = queue[index2].oppositePointer;
	tempPointer[queue[index2].oppositeIndex].oppositeIndex = index2;
	//printf("1_���� �ε��� : %d, ���� �� : %lld, �ݴ��� �� : %lld, �ݴ��� �ε��� �� : %d\n", index1, queue[index1].value, queue[index1].oppositePointer[queue[index1].oppositeIndex].value, queue[index1].oppositePointer[queue[index1].oppositeIndex].oppositeIndex);
	//printf("2_���� �ε��� : %d, ���� �� : %lld, �ݴ��� �� : %lld, �ݴ��� �ε��� �� : %d\n", index2, queue[index2].value, queue[index2].oppositePointer[queue[index2].oppositeIndex].value, queue[index2].oppositePointer[queue[index2].oppositeIndex].oppositeIndex);
	
	return;
}
