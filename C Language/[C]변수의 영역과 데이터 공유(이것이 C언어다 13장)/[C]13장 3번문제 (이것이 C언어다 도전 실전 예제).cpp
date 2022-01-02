#include<stdio.h>

char *my_token(char *ps);

int main(void)
{
	char str[80];
	char *p;
	
	printf("���� �Է� : ");
	gets(str);
	
	while((p = my_token(str)) != NULL)
	{
		printf("%s\n", p);
	}
	scanf("%d");
	
	return 0;
}

char *my_token(char *ps)
{
	static int addIndex;
	static char voca[80];
	int startIndex = addIndex;
	int vocaIndex = 0;
	
	if(*(ps+addIndex) == '\0')	return NULL;
	
	while(*(ps+addIndex) != ' ')
	{
		voca[vocaIndex++] = ps[addIndex];
		addIndex++;
	}
	voca[vocaIndex] = '\0';
	addIndex++;
	
	return voca;
}


/*
���� 3 �ܾ� ���� ���α׷� 
 - Ű����� �� ���� ������ �Է��� �Ŀ� �ܾ �и��Ͽ� ����ϴ� ���α׷��� �ۼ��մϴ�. ��, ���忡�� �ܾ �и��Ͽ� �� ���� �ּҸ� ��ȯ�ϴ� �Լ��� ����� �����մϴ�.
   <char *my_token(char *ps)> �Ű����� ps�� �ܾ �и��� ������ �����͸� ��ȯ���� �и��� �ܾ��� �ּ��Դϴ�.
   �Լ��� �ݺ� ȣ���ϸ� ������ ��� �ܾ �и��� ������ �� �ܾ �ּҸ� ��ȯ�դ���. �Լ� �ȿ����� ���� ������ ����Ͽ� ��� ���� �ܾ��� ��ġ�� ����մϴ�. 
*/ 
