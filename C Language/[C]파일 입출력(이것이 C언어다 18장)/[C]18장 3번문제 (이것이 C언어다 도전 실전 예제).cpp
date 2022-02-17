#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
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
		printf("%s - %.0lf원\n", books[i].name, books[i].sales);
		fprintf(ofp, "%s - %.0lf원\n", books[i].name, books[i].sales);
	}
	
	printf("프로그램 완료\n");
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
}


/*
도전 3 출판사 매출관리 프로그램
 -  책 제목, 매출단가(단위는 만원), 판매 부수(양수는 출고, 음수는 반품)를 저장한 파일에서 데이터를 읽어 도서별 최종 매출액을 출력합니다. 
    책의 종류는 10개 이하로 가정하며 매출이 가장 높은 책부터 정렬하여 파일로 출력합니다. 
*/ 
