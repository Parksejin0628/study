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
	
	printf("�Է� ������ ũ�� : %d\n", inputSize);
	printf("��� ������ ũ�� : %u\n", outputSize);
	
	
	scanf("%d");
	
	return 0;
}


/*
���� 1 ���� ��ȯ ���α׷�  
 - �ؽ�Ʈ ���Ͽ� ����� 8�ڸ� ���� 10���� �Է��Ͽ� ���̳ʸ� ���Ϸ� ����ϰ� �Է��� ���ϰ� ����� ������ ����Ʈ ���� ȭ�鿡 ǥ���մϴ�. 
 �Է� ������ �޸��� ���α׷����� ���ڸ� �� �ٿ� �ϳ��� �ۼ��ϸ� ������ ���ڸ� �Է��� �Ŀ��� ���͸� �ļ� ���� �ٲ�� �ۼ��մϴ�. 
*/ 
