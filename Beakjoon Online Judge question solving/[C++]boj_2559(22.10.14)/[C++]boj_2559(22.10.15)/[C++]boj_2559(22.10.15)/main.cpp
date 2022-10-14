#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::endl;
using std::cin;

class SolvingQuestion
{
private:
	int n, k;
	int* num;
	int sum;
	int max;
public:
	SolvingQuestion(int n, int k) : n(n), k(k), sum(0), max(0)
	{
		num = new int[n];
	}
	~SolvingQuestion()
	{
		delete[]num;
	}
	void input()
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		calSum();
	}
	void calSum()
	{
		//cout << "check F : calSum / start" << endl;
		for (int i = 0; i < k; i++)
		{
			//cout << "check F : calSum / sum += num[i]" << endl;
			sum += num[i];
		}
		//cout << "check F : calSum / middle" << endl;
		max = sum;
		for (int i = k; i < n; i++)
		{
			sum = sum + num[i] - num[i - k];
			if (max < sum)
			{
				max = sum;
				//cout << "max °»½Å : " << max << endl;
			}
		}
	}
	void printAnswer()
	{
		printf("%d\n", max);
	}
};

int main(void)
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	SolvingQuestion solvingQuestion(n, k);

	solvingQuestion.input();
	solvingQuestion.printAnswer();

	return 0;
}