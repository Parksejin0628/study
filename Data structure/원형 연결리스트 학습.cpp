#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Listnode{
	element data;
	struct Listnode* link;
}clistnode;

clistnode* clistnode_insertFirst(clistnode *head, element input);
clistnode* clistnode_insertLast(clistnode *head, element input);
clistnode* clistnode_print(clistnode *head);

int main(void)
{
	int n = 0;
	clistnode *head = NULL;
	
	head = clistnode_insertFirst(head, 10);
	head = clistnode_insertLast(head, 20);
	head = clistnode_insertFirst(head, 30);
	head = clistnode_insertLast(head, 40);
	
	clistnode_print(head);
	
	scanf("%d",&n);
	
	return 0;
}

clistnode* clistnode_insertFirst(clistnode *head, element input)
{
	clistnode *p = (clistnode*)malloc(sizeof(clistnode));
	p->data = input;
	p->link = NULL;
	if(head == NULL)
	{
		head = p;
		p->link = head;
	}
	else
	{
		p->link = head->link;
		head->link = p;
	}
	
	return head;
}
clistnode* clistnode_insertLast(clistnode *head, element input)
{
	clistnode *p = (clistnode*)malloc(sizeof(clistnode));
	p->data = input;
	p->link = NULL;
		if(head == NULL)
		{
			head = p;
			p->link = head;
		}
		else
		{
			p->link = head -> link;
			head->link = p;
			head = p;
		}
}

clistnode* clistnode_print(clistnode *head)
{
	printf("현재 리스트 : ");
	for(clistnode *p = head->link ; p != head ; p = p->link)
	{
		printf("%d ", p->data);
	}
	printf("%d\n", head->data);
	
	return head;
}
