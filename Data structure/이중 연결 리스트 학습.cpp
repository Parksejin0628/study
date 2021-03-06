#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Dnode{
	element data;
	struct Dnode* llink;
	struct Dnode* rlink;
}dnode;

void dnode_insert(dnode* before, element data);
void dnode_delete(dnode* head, dnode* removed);
void dnode_print(dnode* head);

int main(void)
{
	int n = 0;
	
	dnode* head = (dnode*)malloc(sizeof(dnode));
	head->llink = head;
	head->rlink = head;
	
	dnode_insert(head, 10);
	dnode_insert(head, 20);
	dnode_insert(head, 30);
	dnode_insert(head, 40);
	dnode_delete(head, head->rlink->rlink);
	dnode_print(head);
	
	scanf("%d", &n);
	
	return 0;
}

void dnode_insert(dnode* before, element data)
{
	dnode* newNode = (dnode*)malloc(sizeof(dnode));
	newNode->data = data;
	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;
	
	return;
}

void dnode_delete(dnode* head, dnode* removed)
{
	if(removed == head)
	{
		printf("헤드노드는 삭제할 수 없습니다.\n");
	}
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
	
	return; 
}

void dnode_print(dnode* head)
{
	printf("현재 리스트 값 : ");
	for(dnode *p = head->rlink; p!=head; p = p->rlink)
	{
		printf("%d ", p->data);
	}
	printf("\n");
}
