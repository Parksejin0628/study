#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char **word;
	char input_word[80]; 
	char last = '\0';
	int cnt = 0;
	int i = 0;
	int overlap = 0;
	
	word = (char**)malloc(sizeof(char*));
	
	while(1)
	{
		printf("�ܾ� �Է� : ");
		scanf("%s", input_word);
		if(strcmp(input_word, "end") == 0)	break;
		if(input_word[0] != last && cnt != 0)
		{
			printf("# �ܾ� �ձⰡ �Ұ����մϴ�!\n");
			continue;
		}
		for(i=0; i<cnt; i++)
		{
			if(strcmp(word[i], input_word) == 0)
			{
				overlap = 1;
			}
		}
		if(overlap)
		{
			printf("# �̹� �����ϴ� �ܾ��Դϴ�!\n");
			overlap = 0;
			continue;
		}
		cnt++;
		word = (char**)realloc(word, cnt * sizeof(char*));
		word[cnt-1] = (char*)malloc(strlen(input_word) + 1);
		last = input_word[strlen(input_word)-1]; 	
		
		strcpy(word[cnt-1], input_word);
	} 
	for(i=0; i<cnt; i++)
	{
		printf("%s ", word[i]);
	}
	
	scanf("%d");
	
	return 0;
}


/*
���� 3 ���� �ձ� ���α׷�
 - �ܾ �Է��Ͽ� ���� �ձ⸦ �մϴ�. �̹� �Էµ� �ܾ�� ���� �ձⰡ ���� �ʴ� �ܾ�� Ȯ���Ͽ� �����մϴ�. end�� �Է��ϸ� �Է��� ������ �� ���� �Է��� ��� �ܾ ���ʷ� ����մϴ�.
  �Է��� �ܾ�� �� ���̿� �´� ���� �Ҵ� ������ �����ϸ� �Է� ������ �ܾ� ���� �ִ� 100���� �����մϴ�. 
*/ 
