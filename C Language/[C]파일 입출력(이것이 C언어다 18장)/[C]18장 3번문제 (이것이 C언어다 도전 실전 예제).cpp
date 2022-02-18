#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Book
{
	char name[40];
	double sales;
}book;

int main(void)
{
	book books[10];
	book temp;
	FILE *ifp;
	FILE *ofp;
	int count = 0;
	char tempName[40];
	double price = 0;
	int saleCount = 0;
	int res = 0;
	int index = -1;
	
	ifp = fopen("que3Input.txt", "r");
	if(ifp == NULL)
	{
		printf("ifp������ ������ �ʾҽ��ϴ�.\n");
		scanf("%d");
		
		return 1;
	}
	ofp = fopen("que3Output.txt", "w");
	if(ofp == NULL)
	{
		printf("ofp������ ������ �ʾҽ��ϴ�.\n");
		scanf("%d");
		
		return 1;
	}
	//printf("check1\n");
	while(feof(ifp) == 0)
	{
		printf("count : %d\n", count);
		fgets(tempName, 40, ifp);
		if(tempName[strlen(tempName) - 1] == '\n')
		{
			tempName[strlen(tempName) - 1] = '\0';
		}
		for(int i=0; i<count; i++)
		{
			if(strcmp(tempName, books[i].name) == 0)
			{
				index = i;
				break;
			}
		}
		if(index == -1)
		{
			index = count;
			count++;
			strcpy(books[index].name, tempName);
		}
		fscanf(ifp, "%lf %d", &price, &saleCount);
		printf("%s�� ���� �� ���� : %.0lf\n", books[index].name, books[index].sales);
		books[index].sales += price * saleCount * 10000;
		printf("%s�� ���� �� ���� : %.0lf\n", books[index].name, books[index].sales);
		fgetc(ifp);
		
		index = -1;
	}
	//printf("check2\n");
	for(int i=0; i<count; i++)
	{
		for(int j=i+1; j<count; j++)
		{
			if(books[i].sales < books[j].sales)
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
	//printf("check3\n");
	for(int i=0; i<count; i++)
	{
		printf("%d. %s - %.0lf��\n", i+1, books[i].name, books[i].sales);
		fprintf(ofp, "%d. %s - %.0lf��\n", i+1, books[i].name, books[i].sales);
	}
	//printf("check4\n");
	fclose(ifp);
	fclose(ofp);
	
	scanf("%d");
	
	return 0;
}





/*typedef struct
{
	char name[40];
	double sales;
	int check = 0;
}Book;

void checkOverlap(Book *books, char *name, double price, int num);
void sort(Book *books);

int main(void)
{
	Book books[10];
	FILE *ifp;
	FILE *ofp;
	char tempName[40];
	int tempNum;
	double tempPrice;
	
	ifp = fopen("que3Input.txt", "r");
	if(ifp == NULL)
	{
		printf("ifpError\n");
		scanf("%d");
		return 1;
	}
	ofp = fopen("que3Output.txt", "w");
	if(ofp == NULL)
	{
		printf("ofpError\n");
		scanf("%d");
		return 1;
	}
	//printf("check0\n");
	while(feof(ifp) == 0)
	{
		fgets(tempName, 40, ifp);
		//printf("check1.1, %s\n", tempName);
		fscanf(ifp, "%lf %d", &tempPrice, &tempNum);
		//printf("check1.2\n");
		fgetc(ifp);
		checkOverlap(books, tempName, tempPrice, tempNum);
	}
	//printf("check1\n");
	sort(books);
	for(int i=0; i<10 && books[i].check != 0; i++)
	{
		printf("%s - %.0lf��\n", books[i].name, books[i].sales);
		fprintf(ofp, "%s - %.0lf��\n", books[i].name, books[i].sales);
	}
	
	printf("���α׷� �Ϸ�\n");
	scanf("%d");
	
	return 0;
}

void checkOverlap(Book *books, char *name, double price, int num)
{
	//printf("check2\n");
	int i = 0;
	for(i=0; i<10 && books[i].check != 0; i++)
	{
		printf("check2.1 %s", books[i].name);
		if(strcmp(books[i].name, name) == 0)
		{
			printf("check2.2\n");
			books[i].sales = price * num * 10000;
			return;
		}
	}
	strcpy(books[i].name, name);
	books[i].sales = price * num * 10000;
	books[i].check = 1;
	printf("%s\n", name);
	
	return;
}

void sort(Book *books)
{
	Book temp;
	for(int i=0; i<10; i++)
	{
		if(books[i].check == 0)	break;
		for(int j=i+1; j<10; j++)
		{
			if(books[i].check == 0)	break;
			if(books[i].sales < books[j].sales)
			{
				temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
	
	return;
}*/


/*
���� 3 ���ǻ� ������� ���α׷�
 -  å ����, ����ܰ�(������ ����), �Ǹ� �μ�(����� ���, ������ ��ǰ)�� ������ ���Ͽ��� �����͸� �о� ������ ���� ������� ����մϴ�. 
    å�� ������ 10�� ���Ϸ� �����ϸ� ������ ���� ���� å���� �����Ͽ� ���Ϸ� ����մϴ�. 
*/ 

/*
[��ȹ] 
1. å ������ �Է¹޴´�.
2. ������ �ִ� å���� Ȯ���Ѵ�.
 2.1. ������ �ִ� å�� ��� �ش� å�� �����Ѵ�. 
 2.2. ������ �ִ� å�� �ƴ� ��� å�� ���� �߰��ϰ� �߰��� å�� �����Ѵ�.
3. ������ å�� ����׿� ����ܰ� * �Ǹ� �μ� * 10000 ���� ���Ѵ�.
4. ������� �������� ������ �� ���Ϸ� ����Ѵ�. 

[����]
1. å ������ �Է¹޴´�.
 - "r"���� �� ���Ͽ��� tempName�� fgets�� ���� �Է¹޴´�. 
2. ������ �ִ� å���� Ȯ���Ѵ�.
 - ���� å�� ������ �ľ��ϴ� count������ �ݺ����� strcmp �Լ��� ���� �ߺ��� �̸��� �ִ��� Ȯ���Ѵ�.
 - ���� ��� �ش� �ε����� index�� �����Ѵ�.
 - ���� ��� count++�� �� index = count - 1�� �Ѵ�.
3. ������ å�� ����׿� ����ܰ� * �Ǹ� �μ� * 10000 ���� ���Ѵ�.
 - ����ܰ��� �Ǹ� �μ��� fscanf�� ���� �Է¹޴´�.
 - fscnaf�� �� �� fgetc�Լ��� ���� \n�� �����ش�. 
 - Book ����ü�� sales�� ���� ���Ѵ�.
4. ������� �������� ������ �� ���Ϸ� ����Ѵ�.
 - Book.sales���� �������� ���������� ���� ������ �� ó������ ����Ѵ�. 
*/
