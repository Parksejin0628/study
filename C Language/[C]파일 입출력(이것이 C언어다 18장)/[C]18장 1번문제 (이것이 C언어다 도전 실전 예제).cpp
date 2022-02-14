#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int num[10] = {0};
	int inputSize = 0;
	size_t outputSize = 0; 
	FILE *ifp;
	FILE *ofp;
	
	ifp = fopen("que1Input.txt", "r");
	if(ifp == NULL)
	{
		printf("error\n");
	}
	
	ofp = fopen("que1Output.txt", "wb");
	if(ofp == NULL)
	{
		printf("error\n");
	}
	
	for(int i=0; feof(ifp) == 0; i++)
	{
		fscanf(ifp, "%d", &num[i]);
		inputSize += sizeof(num[i]);
	}
	outputSize += fwrite(num, 1, sizeof(num), ofp);
	
	printf("입력 파일의 크기 : %d\n", inputSize);
	printf("출력 파일의 크기 : %u\n", outputSize);
	
	
	scanf("%d");
	
	return 0;
}


/*
도전 1 파일 변환 프로그램  
 - 텍스트 파일에 저장된 8자리 정수 10개를 입력하여 바이너리 파일로 출력하고 입력한 파일과 출력한 파일의 바이트 수를 화면에 표시합니다. 
 입력 파일은 메모장 프로그램으로 숫자를 한 줄에 하나씩 작성하며 마지막 숫자를 입력한 후에도 엔터를 쳐서 줄이 바뀌도록 작성합니다. 
*/ 
