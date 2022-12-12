#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

int map[502][502] = { 0 };
int dp[502][502] = { 0 };

int searchRoute(int row, int column);

int main(void)
{
	int M, N;

	scanf("%d %d", &M, &N);
	for (int r = 1; r <= M; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			scanf("%d", &map[r][c]);
			dp[r][c] = -1;
		}
	}
	printf("%d", searchRoute(M, N));

	return 0;
}

int searchRoute(int row, int column)
{
	if (row == 1 && column == 1)
	{
		return 1;
	}
	if (dp[row][column] == -1)
	{
		int temp = 0;
		if (map[row][column] < map[row - 1][column])
		{
			temp += searchRoute(row - 1, column);
		}
		if (map[row][column] < map[row + 1][column])
		{
			temp += searchRoute(row + 1, column);
		}
		if (map[row][column] < map[row][column - 1])
		{
			temp += searchRoute(row, column-1);
		}
		if (map[row][column] < map[row][column + 1])
		{
			temp += searchRoute(row, column + 1);
		}
		dp[row][column] = temp;
		//printf("%d, %d 에서 경우의 수 : %d\n", row, column, temp);
	}
	return dp[row][column];
}