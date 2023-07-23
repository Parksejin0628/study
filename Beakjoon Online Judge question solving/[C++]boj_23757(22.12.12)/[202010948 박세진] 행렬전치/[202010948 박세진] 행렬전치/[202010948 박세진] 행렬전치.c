#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define DEFAULT_ROWS 6
#define DEFAULT_COLUMNS 6
#define DEFAULT_COUNT 7
#define ROW 0
#define COLUMN 1
#define VALUE 2

int DEFAULT_VALUE[DEFAULT_COUNT][3] = {
	{0, 3, 7 },
	{ 1, 0, 9 },
	{ 1, 5, 8 },
	{ 3, 0, 6 },
	{ 3, 1, 5 },
	{ 4, 5, 1 },
	{ 5, 2, 2 }};

typedef struct Element
{
	int row;
	int column;
	int value;
}element;

typedef struct Matrix
{
	element* data;
	int rows;
	int columns;
	int count;
}matrix;

element temp[100];

void init_input(matrix* m);							//행렬 값을 입력받는 함수
void init_noInput(matrix* m);						//행렬 값을 pdf파일에 있는 예제로 선언하는 함수
void transposition_matrix(matrix* m);				//행렬전치를 수행하는 함수
void sort_matrix(matrix* m, int start, int end);	//저장한 행렬 배열을 정렬하는 함수(mergeSort)
void print_matrix(matrix* m);						//행렬을 출력하는 함수

int main(void)
{
	matrix m;
	//init_input(&m);
	init_noInput(&m);
	transposition_matrix(&m);
	sort_matrix(&m, 0, m.count - 1);
	print_matrix(&m);
	free(m.data);

	return 0;
}

void init_input(matrix* m)
{
	printf("행의 길이를 입력하시오 : ");
	scanf("%d", &m->rows);
	printf("열의 길이를 입력하시오 : ");
	scanf("%d", &m->columns);
	printf("항의 개수를 입력하시오 : ");
	scanf("%d", &m->count);

	m->data = (element*)malloc(sizeof(element) * (m->count));
	for (int i = 0; i < m->count; i++)
	{
		printf("%d번째 항의 행의 길이를 입력하시오 : ", i + 1);
		scanf("%d", &m->data[i].row);
		printf("%d번째 항의 열의 길이를 입력하시오 : ", i + 1);
		scanf("%d", &m->data[i].column);
		printf("%d번째 항의 값을 입력하시오 : ", i + 1);
		scanf("%d", &m->data[i].value);
	}

	return;
}

void init_noInput(matrix* m)
{
	m->rows = DEFAULT_ROWS;
	m->columns = DEFAULT_COLUMNS;
	m->count = DEFAULT_COUNT;
	m->data = (element*)malloc(sizeof(element) * (m->count));
	
	for (int i = 0; i < m->count; i++)
	{
		m->data[i].row = DEFAULT_VALUE[i][ROW];
		m->data[i].column = DEFAULT_VALUE[i][COLUMN];
		m->data[i].value = DEFAULT_VALUE[i][VALUE];
	}

	return;
}

void transposition_matrix(matrix* m)
{
	int temp = 0;

	for (int i = 0; i < m->count; i++)
	{
		temp = m->data[i].row;
		m->data[i].row = m->data[i].column;
		m->data[i].column = temp;
	}

	return;
}

void sort_matrix(matrix* m, int start, int end)
{
	//static element* temp = (element*)malloc(sizeof(element) * m->count);

	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	sort_matrix(m, start, mid);
	sort_matrix(m, mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = start;

	for (; k <= end; k++)
	{
		if (i > mid || j > end)
		{
			break;
		}
		if (m->data[i].row < m->data[j].row)
		{
			temp[k].column = m->data[i].column;
			temp[k].row = m->data[i].row;
			temp[k].value = m->data[i].value;
			i++;
		}
		else if (m->data[i].row > m->data[j].row)
		{
			temp[k].column = m->data[j].column;
			temp[k].row = m->data[j].row;
			temp[k].value = m->data[j].value;
			j++;
		}
		else if (m->data[i].row == m->data[j].row)
		{
			if (m->data[i].column <= m->data[j].column)
			{
				temp[k].column = m->data[i].column;
				temp[k].row = m->data[i].row;
				temp[k].value = m->data[i].value;
				i++;
			}
			else
			{
				temp[k].column = m->data[j].column;
				temp[k].row = m->data[j].row;
				temp[k].value = m->data[j].value;
				j++;
			}
		}
	}
	if (i > mid)
	{
		for (; k <= end; k++)
		{
			temp[k].column = m->data[j].column;
			temp[k].row = m->data[j].row;
			temp[k].value = m->data[j].value;
			j++;
		}
	}
	else
	{
		for (; k <= end; k++)
		{
			temp[k].column = m->data[i].column;
			temp[k].row = m->data[i].row;
			temp[k].value = m->data[i].value;
			i++;
		}
	}
	for (k = start; k <= end; k++)
	{
		m->data[k].column = temp[k].column;
		m->data[k].row = temp[k].row;
		m->data[k].value = temp[k].value;
	}

	/*if (start == 0 && end == m->count - 1)
	{
		free(temp);
	}*/

	return;
}

void print_matrix(matrix* m)
{
	for (int i = 0; i < m->count; i++)
	{
		printf("(%d %d %d)\n", m->data[i].row, m->data[i].column, m->data[i].value);
	}

	return;
}

