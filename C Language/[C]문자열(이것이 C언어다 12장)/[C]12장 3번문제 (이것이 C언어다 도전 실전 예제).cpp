#include<stdio.h>
#include<string.h> 

int main(void)
{
	char sentence[1000] = {'\0'};
	char input[100] = {'\0'};
	int result = 0;
	int i = 0;
	
	printf("���� �Է� : ");
	gets(sentence);
	while(1)
	{
		printf("�˻��� ���ڿ� �Է� (����� end) : ");
		gets(input);
		if(strcmp(input, "end") == 0)
		{
			break;
		}
		for(int i=0; sentence[i] != '\0'; i++)
		{
			//printf("check1 : %s / %s - %d, %d\n", sentence+i, input, strncmp(sentence + i, input, strlen(input)), strlen(input));
			if(strncmp(sentence + i, input, strlen(input)) == 0)
			{
				result ++;
				i += (strlen(input)-1);
			}
		}
		printf("�˻���� : %d��\n", result); 
		result = 0;
	}
	
	scanf("%d");
	
	return 0;
}


/*
���� 3 ���ڿ� �˻� ���α׷� 
 - Ű����� �Է��� ���忡�� ���ϴ� ���ڿ��� ã�� �� ������ ����ϴ� ���α׷��� ����ϴ�. 
 ������ �� ���� �Է��ϸ� ���ڿ� �˻��� end�� �Էµ� ������ �ݺ��մϴ�. 
*/ 
