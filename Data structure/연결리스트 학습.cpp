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
		printf("���ڸ� �Է��Ͽ� ������ ����� ����� �� �ֽ��ϴ�.\n");
		printf("(1) : ����Ʈ�� �����͸� �����մϴ�.\n");
		printf("(2) : ����Ʈ�� �����͸� �����մϴ�.\n");
		printf("(3) : ���� ����Ʈ�� �ִ� ��� �����͸� ����մϴ�.\n");
		printf("(4) : ���� ����Ʈ�� �ִ� ��� �����͸� �����մϴ�.\n");
		printf("(5) : ���� ����Ʈ���� Ư�� �����͸� Ž���մϴ�.\n");
		printf("(6) : ���� ����Ʈ�� �������� ����ϴ�.\n");
		printf("����(-1�Է½� ���α׷��� �����մϴ�.) : ");
		scanf("%d",&select);
		if(select == 1)
		{
			head = listnode_print(head);
			printf("�߰��� �����͸� �Է��Ͻÿ� : ");
			scanf("%d",&input);
			printf("�߰��� ��ġ�� �Է��Ͻÿ�(0���� ����) : ");
			scanf("%d",&pos);
			head = listnode_insert(head, pos, input);
		}
		else if(select == 2)
		{
			head = listnode_print(head);
			printf("������ �������� ��ġ�� �Է��Ͻÿ�(0���� ����) : ");
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
			printf("����Ʈ�� ��� �����͸� �����Ͽ����ϴ�.\n");
		}
		else if(select == 5)
		{
			printf("ã������ �����͸� �Է��Ͻÿ� : ");
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
		printf("����Ʈ�� ����� �����Ͱ� ���� �ڵ����� ����Ʈ�� ù��°�� �����Ͱ� ����˴ϴ�.\n");
		head = newNode;
		printf("%d��° ����Ʈ�� %d�����͸� ���������� �����Ͽ����ϴ�.\n", 0, data);
		
		return head;
	}
	//printf("check5\n");
	pre = head;
	if(pos == 0)
	{
		newNode->link = head;
		newNode -> link = head;
		head = newNode;
		printf("%d��° ����Ʈ�� %d�����͸� ���������� �����Ͽ����ϴ�.\n", insertedPos, data);
		return head;
	}	
	insertedPos = 1;
	for(int i=1; i<pos; i++)
	{
		if(pre->link == NULL)
		{
			printf("����Ʈ�� ���������� ū ���ڸ� �Է��ϼ̽��ϴ�. ����Ʈ�� �������� ���ο� ��带 �߰��մϴ�...\n");
			break;
		}
		pre = pre->link;
		insertedPos++;
	}
	newNode->link = pre->link;
	pre->link = newNode;
	printf("%d��° ����Ʈ�� %d�����͸� ���������� �����Ͽ����ϴ�.\n", insertedPos, data);
	
	return head;  
}

listnode* listnode_delete(listnode* head, int pos)
{
	listnode *pre = head;
	listnode *removedNode = head;
	int insertedPos = 0;
	
	if(head == NULL)
	{
		printf("������ ����Ʈ�� �����ϴ�.\n"); 
		
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
				printf("����Ʈ�� ���������� ū ���ڸ� �Է��ϼ̽��ϴ�. ����Ʈ�� ������ ��带 �����մϴ�...\n");
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
	
	printf("%d��° ����Ʈ�� �����͸� �����Ͽ����ϴ�.\n", insertedPos);
	return head;
}

listnode* listnode_print(listnode* head)
{
	printf("���� ����� ������ : ");
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
			printf("����Ʈ�� %d��°����  %d�� ã�ҽ��ϴ�.\n", pos, target);
			return head;
		}
		pos++;
	}
	printf("����Ʈ�� %d�� �������� �ʽ��ϴ�!\n", target);
	
	return head;
}

listnode* listnode_reverse(listnode* head)
{
	if(head == NULL)
	{
		printf("�ش� ����Ʈ�� �����Ͱ� �����ϴ�.\n");
		
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
	printf("���������� ����Ʈ�� �������� ��������ϴ�.\n");
	
	return head;
}
