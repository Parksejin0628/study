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
도전 2 단어 검출 프로그램
 - 텍스트 파일에서 등록된 단어 이외의 단어를 찾아 새로운 파일에 출력합니다.
   모든 단어의 길이는 최대 20자, 등록 단어 수는 최대 10개로 제한하며 검출 대상 단어 수는 제한이 없습니다. 
*/ 
