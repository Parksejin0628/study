#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

class SolvingQuestion
{
private:
	int input_count;
	long long divisor;
	long long* sum;
	long long* remainder;
	long long answer;
public:
	SolvingQuestion(int n, int m) : input_count(n), divisor(m), answer(0)
	{
		sum = new long long[input_count];
		remainder = new long long[divisor];
		for (int i = 0; i < divisor; i++)
		{
			remainder[i] = 0;
		}
	}
	~SolvingQuestion()
	{
		delete[]sum;
		delete[]remainder;
	}
	void inputNum()
	{
		long long num;
		scanf("%lld", &num);
		sum[0] = num;
		remainder[sum[0] % divisor]++;
		for (int i = 1; i < input_count; i++)
		{
			scanf("%lld", &num);
			sum[i] = sum[i - 1] + num;
			remainder[sum[i] % divisor]++;
		}
	}
	void calAnswer()
	{
		answer += remainder[0];
		for (int i = 0; i < divisor; i++)
		{
			answer += remainder[i] * (remainder[i] - 1) / 2;
		}
	}
	void printAnswer()
	{
		printf("%lld", answer);
	}

	
};

int main(void)
{
	int n = 0;
	int m = 0;

	scanf("%d %d", &n, &m);
	SolvingQuestion solvingQuestion(n, m);
	solvingQuestion.inputNum();
	solvingQuestion.calAnswer();
	solvingQuestion.printAnswer();

	return 0;
}