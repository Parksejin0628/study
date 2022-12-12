#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::endl;
using std::cin;

typedef struct Coordinate
{
	int row;
	int column;
}coordinate;

int matrix[1025][1025] = { 0 };
int prefixSum[1025][1025] = { 0 };

int main(void)
{
	int matrix_size = 0;
	int question_count = 0;
	int prefixSum_row = 0;
	coordinate section[2];

	scanf("%d %d", &matrix_size, &question_count);
	for (int row = 1; row <= matrix_size; row++)
	{
		for (int column = 1; column <= matrix_size; column++)
		{
			scanf("%d", &matrix[row][column]);
			prefixSum_row += matrix[row][column];
			prefixSum[row][column] = prefixSum[row - 1][column] + prefixSum_row;
		}
		prefixSum_row = 0;
	}

	for (int i = 1; i <= question_count; i++)
	{
		scanf("%d %d %d %d", &section[0].row, &section[0].column, &section[1].row, &section[1].column);
		printf("%d\n", prefixSum[section[1].row][section[1].column] - prefixSum[section[0].row - 1][section[1].column] - prefixSum[section[1].row][section[0].column - 1] + prefixSum[section[0].row - 1][section[0].column - 1]);
	}

	return 0;
}