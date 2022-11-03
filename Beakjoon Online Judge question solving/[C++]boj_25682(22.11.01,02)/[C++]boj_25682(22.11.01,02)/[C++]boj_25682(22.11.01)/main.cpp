#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

int board[2001][2001] = { 0 };
char input[2010] = { '\0' };
int prefixSum_blackStart[2001][2001] = { 0 };
int prefixSum_whiteStart[2001][2001] = { 0 };

int main(void)
{
	int n = 0;
	int m = 0;
	int k = 0;

	int prefixSum_blackStart_row = 0;
	int prefixSum_whiteStart_row = 0;
	int min = 200000000;
	int temp = 0;

	scanf("%d %d %d", &n, &m, &k);
	for (int r = 1; r <= n; r++)
	{
		scanf("%s", input);
		for (int c = 1; c <= m; c++)
		{
			if (input[c-1] == 'B')
			{
				board[r][c] = 0;
				if ((r + c) % 2 == 0)
				{
					prefixSum_blackStart_row++;
				}
				else
				{
					prefixSum_whiteStart_row++;
				}
			}
			else if (input[c-1] == 'W')
			{
				board[r][c] = 1;
				if ((r + c) % 2 == 0)
				{
					prefixSum_whiteStart_row++;
				}
				else
				{
					prefixSum_blackStart_row++;
				}
			}
			else
			{
				printf("error\n");
			}
			prefixSum_blackStart[r][c] = prefixSum_blackStart[r - 1][c] + prefixSum_blackStart_row;
			prefixSum_whiteStart[r][c] = prefixSum_whiteStart[r - 1][c] + prefixSum_whiteStart_row;
		}
		prefixSum_blackStart_row = 0;
		prefixSum_whiteStart_row = 0;
	}
	
	for (int r = n; r >= k; r--)
	{
		for (int c = m; c >= k; c--)
		{
			temp = prefixSum_blackStart[r][c] - prefixSum_blackStart[r - k][c] - prefixSum_blackStart[r][c - k] + prefixSum_blackStart[r - k][c - k];
			if (k * k - temp < min)
			{
				min = k * k - temp;
			}
			temp = prefixSum_whiteStart[r][c] - prefixSum_whiteStart[r - k][c] - prefixSum_whiteStart[r][c - k] + prefixSum_whiteStart[r - k][c - k];
			if (k * k - temp < min)
			{
				min = k * k - temp;
			}
		}
	}
	printf("%d\n", min);

	return 0;
}