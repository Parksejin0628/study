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
		printf("ifp파일이 열리지 않았습니다.\n");
		scanf("%d");
		
		return 1;
	}
	ofp = fopen("que3Output.txt", "w");
	if(ofp == NULL)
	{
		printf("ofp파일이 열리지 않았습니다.\n");
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
		printf("%s의 적용 전 매출 : %.0lf\n", books[index].name, books[index].sales);
		books[index].sales += price * saleCount * 10000;
		printf("%s의 적용 후 매출 : %.0lf\n", books[index].name, books[index].sales);
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
		printf("%d. %s - %.0lf원\n", i+1, books[i].name, books[i].sales);
		fprintf(ofp, "%d. %s - %.0lf원\n", i+1, books[i].name, books[i].sales);
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
}*/


/*
도전 3 출판사 매출관리 프로그램
 -  책 제목, 매출단가(단위는 만원), 판매 부수(양수는 출고, 음수는 반품)를 저장한 파일에서 데이터를 읽어 도서별 최종 매출액을 출력합니다. 
    책의 종류는 10개 이하로 가정하며 매출이 가장 높은 책부터 정렬하여 파일로 출력합니다. 
*/ 

/*
[계획] 
1. 책 제목을 입력받는다.
2. 기존에 있는 책인지 확인한다.
 2.1. 기존에 있는 책인 경우 해당 책을 지정한다. 
 2.2. 기존에 있는 책이 아닌 경우 책을 새로 추가하고 추가한 책을 지정한다.
3. 지정한 책의 매출액에 매출단가 * 판매 부수 * 10000 값을 더한다.
4. 매출액을 기준으로 정렬한 후 파일로 출력한다. 

[구현]
1. 책 제목을 입력받는다.
 - "r"모드로 연 파일에서 tempName에 fgets를 통해 입력받는다. 
2. 기존에 있는 책인지 확인한다.
 - 현재 책의 갯수를 파악하는 count값까지 반복문과 strcmp 함수를 통해 중복된 이름이 있는지 확인한다.
 - 있을 경우 해당 인덱스를 index에 저장한다.
 - 없을 경우 count++한 뒤 index = count - 1를 한다.
3. 지정한 책의 매출액에 매출단가 * 판매 부수 * 10000 값을 더한다.
 - 매출단가와 판매 부수를 fscanf를 통해 입력받는다.
 - fscnaf를 한 후 fgetc함수를 통해 \n을 지워준다. 
 - Book 구조체의 sales에 값을 더한다.
4. 매출액을 기준으로 정렬한 후 파일로 출력한다.
 - Book.sales값을 기준으로 버블정렬을 통해 정렬한 후 처음부터 출력한다. 
*/
