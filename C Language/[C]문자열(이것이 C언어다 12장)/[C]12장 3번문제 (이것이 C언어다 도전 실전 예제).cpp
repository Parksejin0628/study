#include<stdio.h>
#include<string.h> 

int main(void)
{
	char sentence[1000] = {'\0'};
	char input[100] = {'\0'};
	int result = 0;
	int i = 0;
	
	printf("���� �Է� : ");
	scanf("%s", sentence);
	while(1)
	{
		printf("�˻��� ���ڿ� �Է� (����� end) : ");
		scanf("%s", input);
		if(strcmp(input, "end") == 0)
		{
			break;
		}
		for(int i=0; sentence[i] = '\0'; i++)
		{
			if(strncmp(sentence + i, input, ))
		}
		printf("�˻���� : %d\n", result); 
	}
	
	scanf("%d");
	
	return 0;
}


/*
���� 3 ���ڿ� �˻� ���α׷� 
 - Ű����� �Է��� ���忡�� ���ϴ� ���ڿ��� ã�� �� ������ ����ϴ� ���α׷��� ����ϴ�. 
 ������ �� ���� �Է��ϸ� ���ڿ� �˻��� end�� �Էµ� ������ �ݺ��մϴ�. 
*/ 
