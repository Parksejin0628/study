#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checkOverlap(char (*registeredWord)[25], char *word);

int main(void)
{
	char registeredWord[10][25];
	char inputWord[25];
	FILE *afp;
	FILE *bfp;
	FILE *cfp;
	
	afp = fopen("que2A.txt", "r");
	bfp = fopen("que2B.txt", "r");
	cfp = fopen("que2C.txt", "w");
	
	if(afp == NULL || bfp == NULL || cfp == NULL)
	{
		printf("error!\n");
	}
	//printf("check0\n");
	for(int i=0; feof(afp) == 0; i++)
	{
		//printf("check1\n");
		fgets(registeredWord[i], 25, afp);
	}
	//printf("check0\n");
	while(feof(bfp) == 0)
	{
		//printf("check2\n");
		fgets(inputWord, 25, bfp);
		if(checkOverlap(registeredWord, inputWord) == 0)
		{
			fputs(inputWord, cfp);
		}
	}
	fclose(afp);
	fclose(bfp);
	fclose(cfp);
	
	scanf("%d");
	
	return 0;
}

int checkOverlap(char (*registeredWord)[25], char *word)
{
	for(int i=0; strcmp(registeredWord[i], "\0") != 0; i++)
	{
		if(strcmp(registeredWord[i], word) == 0)
		{
			return 1;
		}
		//printf("check3\n");
	}
	
	return 0;
}


/*
���� 2 �ܾ� ���� ���α׷�
 - �ؽ�Ʈ ���Ͽ��� ��ϵ� �ܾ� �̿��� �ܾ ã�� ���ο� ���Ͽ� ����մϴ�.
   ��� �ܾ��� ���̴� �ִ� 20��, ��� �ܾ� ���� �ִ� 10���� �����ϸ� ���� ��� �ܾ� ���� ������ �����ϴ�. 
*/ 
