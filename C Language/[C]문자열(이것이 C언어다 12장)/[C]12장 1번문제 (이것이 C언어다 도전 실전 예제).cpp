#include<stdio.h>
#include<string.h>

int main(void)
{
	char str[3][20] = {'\0'};
	char temp[20];
	int i = 0;
	int j = 0;
	
	printf("�� �ܾ� �Է� : ");
	for(i=0; i<3; i++)
	{
		scanf("%s", str[i]);
	}
	
	for(i=0; i<3; i++)
	{
		for(j=i+1; j<3; j++)
		{
			if(strcmp(str[i], str[j]) == 1)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}
	
	printf("%s, %s, %s", str[0], str[1], str[2]);
	scanf("%d");
	
	return 0;
}



/*
���� 1 �ܾ� ���� ���α׷� 
 - Ű����� �� �ܾ �Է��Ͽ� ���� ������� ����մϴ�. 
*/ 
