#include<stdio.h>
#include<string.h> 

int main(void)
{
	char output[1000] = {'\0'};
	char input[100] = {'\0'};
	while(1)
	{
		printf("�ܾ� �Է� : ");
		scanf("%s", input);
		if(strcmp(input, "end") == 0)
		{
			break;
		}
		strcat(output, input);
		strcat(output, " ");
		printf("��������� ���ڿ� : %s\n", output); 
	}
	
	scanf("%d");
	
	return 0;
}



/*
���� 2 �ܾ� �̾� ����ϱ�
 - Ű����� �Է��� �ܾ �̾�ٿ� �ݺ� ����մϴ�. end�� �Է��ϸ� �ݺ��� �����մϴ�. 
*/ 
