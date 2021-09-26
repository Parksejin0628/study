#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode *link;
}listnode;

listnode* listnode_insert(listnode* head, int pos, element data);
listnode* listnode_delete(listnode* head, int pos);
listnode* listnode_print(listnode* head);
listnode* listnode_clear(listnode* head);
listnode* listnode_search(listnode* head, element target);
listnode* listnode_reverse(listnode* head);

int main(void)
{
	listnode *head = NULL;
	int select = 0;
	element input = 0;
	int pos = 0;
	
	while(select != -1)
	{
		printf("------------------------------------\n");
		printf("숫자를 입력하여 다음의 명령을 사용할 수 있습니다.\n");
		printf("(1) : 리스트에 데이터를 저장합니다.\n");
		printf("(2) : 리스트에 데이터를 제거합니다.\n");
		printf("(3) : 현재 리스트에 있는 모든 데이터를 출력합니다.\n");
		printf("(4) : 현재 리스트에 있는 모든 데이터를 제거합니다.\n");
		printf("(5) : 현재 리스트에서 특정 데이터를 탐색합니다.\n");
		printf("(6) : 현재 리스트를 역순으로 만듭니다.\n");
		printf("선택(-1입력시 프로그램을 종료합니다.) : ");
		scanf("%d",&select);
		if(select == 1)
		{
			head = listnode_print(head);
			printf("추가할 데이터를 입력하시오 : ");
			scanf("%d",&input);
			printf("추가할 위치를 입력하시오(0부터 시작) : ");
			scanf("%d",&pos);
			head = listnode_insert(head, pos, input);
		}
		else if(select == 2)
		{
			head = listnode_print(head);
			printf("제거할 데이터의 위치를 입력하시오(0부터 시작) : ");
			scanf("%d",&pos);
			head = listnode_delete(head, pos);
		}
		else if(select == 3)
		{
			head = listnode_print(head);
		}
		else if(select == 4)
		{
			head = listnode_clear(head);
			printf("리스트의 모든 데이터를 제거하였습니다.\n");
		}
		else if(select == 5)
		{
			printf("찾으려는 데이터를 입력하시오 : ");
			scanf("%d", &input);
			head = listnode_search(head, input);
		}
		else if(select == 6)
		{
			head = listnode_reverse(head);
		}
		printf("\n\n");
	}
	
	head = listnode_clear(head);
	
	return 0;
}

listnode* listnode_insert(listnode *head, int pos, element data)
{
	listnode *newNode = (listnode*)malloc(sizeof(listnode));
	listnode *pre = NULL;
	int insertedPos = 0;
	
	newNode->data = data;
	newNode->link = NULL;
	if(head == NULL)
	{
		printf("리스트에 저장된 데이터가 없어 자동으로 리스트의 첫번째에 데이터가 저장됩니다.\n");
		head = newNode;
		printf("%d번째 리스트에 %d데이터를 성공적으로 저장하였습니다.\n", 0, data);
		
		return head;
	}
	//printf("check5\n");
	pre = head;
	if(pos == 0)
	{
		newNode->link = head;
		newNode -> link = head;
		head = newNode;
		printf("%d번째 리스트에 %d데이터를 성공적으로 저장하였습니다.\n", insertedPos, data);
		return head;
	}	
	insertedPos = 1;
	for(int i=1; i<pos; i++)
	{
		if(pre->link == NULL)
		{
			printf("리스트의 마지막보다 큰 숫자를 입력하셨습니다. 리스트의 마지막에 새로운 노드를 추가합니다...\n");
			break;
		}
		pre = pre->link;
		insertedPos++;
	}
	newNode->link = pre->link;
	pre->link = newNode;
	printf("%d번째 리스트에 %d데이터를 성공적으로 저장하였습니다.\n", insertedPos, data);
	
	return head;  
}

listnode* listnode_delete(listnode* head, int pos)
{
	listnode *pre = head;
	listnode *removedNode = head;
	int insertedPos = 0;
	
	if(head == NULL)
	{
		printf("삭제할 리스트가 없습니다.\n"); 
		
		return head;
	}
	else if(pos == 0)
	{
		head = head->link;
		free(removedNode);
		pos = 0;
	}
	else
	{
		insertedPos = 1;
		for(int i=1; i<pos; i++)
		{
			if(pre->link == NULL)
			{
				printf("리스트의 마지막보다 큰 숫자를 입력하셨습니다. 리스트의 마지막 노드를 제거합니다...\n");
				break;
			}
			pre = pre->link;
			insertedPos++;
		}
		removedNode = pre->link;
		if(removedNode == NULL)
		{
			removedNode = pre;
			if(insertedPos == 1)
			{
				head = NULL;
			}
		}
		else
		{
			pre->link = removedNode->link;
		}
		free(removedNode);
	}
	
	printf("%d번째 리스트의 데이터를 제거하였습니다.\n", insertedPos);
	return head;
}

listnode* listnode_print(listnode* head)
{
	printf("현재 저장된 데이터 : ");
	for(listnode *p = head; p!=NULL; p = p->link)
	{
		printf("%d ", p->data);
	}
	printf("\n");
	
	return head;
}

listnode* listnode_clear(listnode* head)
{
	listnode *removedNode = NULL;
	listnode *p = head;
	while(p != NULL)
	{
		removedNode = p;
		p = p->link;
		free(removedNode);
	}
	
	return NULL;
}

listnode* listnode_search(listnode *head, element target)
{
	int pos = 0; 
	for(listnode *p = head; p != NULL; p = p->link)
	{
		if(p->data == target)
		{
			printf("리스트에 %d번째에서  %d를 찾았습니다.\n", pos, target);
			return head;
		}
		pos++;
	}
	printf("리스트에 %d는 존재하지 않습니다!\n", target);
	
	return head;
}

listnode* listnode_reverse(listnode* head)
{
	if(head == NULL)
	{
		printf("해당 리스트에 데이터가 없습니다.\n");
		
		return NULL;
	}
	
	listnode* pre = NULL;
	listnode* now = NULL;
	listnode* next = head;
	
	while(next != NULL)
	{
		pre = now;
		now = next;
		next = next->link;
		now->link = pre;
	}
	
	head = now;
	printf("성공적으로 리스트를 역순으로 만들었습니다.\n");
	
	return head;
}
