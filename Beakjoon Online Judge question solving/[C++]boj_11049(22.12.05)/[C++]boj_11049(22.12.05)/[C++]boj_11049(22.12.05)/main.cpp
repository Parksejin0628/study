#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

class matrix
{
private:
	int row;
	int column;
public:
	matrix() : row(0), column(0)
	{

	}
	matrix(int r, int c) : row(r), column(c)
	{

	}
	void inputMatrix(int r, int c)
	{
		row = r;
		column = c;
	}
	int operator*(const matrix other) const
	{
		return row * column * other.column;
	}
	int getRow() const
	{
		return row;
	}
	int getColumn() const
	{
		return column;
	}
};

class SolveQuestion
{
private:
	matrix* arr;
	int arrSize;
	int** dp;
public:
	SolveQuestion(int size) : arrSize(size)
	{
		arr = new matrix[size];
		dp = new int* [size] {};
		for (int i = 0; i < size; i++)
		{
			dp[i] = new int[size] {};
		}
	}
	void inputMatrix()
	{
		int r = 0;
		int c = 0;
		for (int i = 0; i < arrSize; i++)
		{
			scanf("%d %d", &r, &c);
			arr[i].inputMatrix(r, c);
		}
	}
	int multiplyMatrix(int left, int right)
	{
		if (left == right)
		{
			return 0;
		}
		if (dp[left][right] == 0)
		{
			int temp = 0;
			int min = 2147483647;
			for (int i = left; i < right; i++)
			{
				temp = multiplyMatrix(left, i) + multiplyMatrix(i + 1, right) + (arr[left].getRow() * arr[i].getColumn() * arr[right].getColumn());
				if (temp < min)
				{
					min = temp;
				}
			}
			dp[left][right] = min;
			//printf("%d ~ %d 구간의 최소값 : %d\n", left, right, min);
		}

		return dp[left][right];
	}
	~SolveQuestion()
	{
		delete[]arr;
		for (int i = 0; i < arrSize; i++)
		{
			delete[]dp[i];
		}
		delete[]dp;
	}
};

int main(void)
{
	int size;

	scanf("%d", &size);

	SolveQuestion solveQuestion(size);
	solveQuestion.inputMatrix();
	printf("%d\n", solveQuestion.multiplyMatrix(0, size-1));

	return 0;
}