#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;


class SolveQuestion
{
private:
	int x_s;
	int y_s;
	int x_e;
	int y_e;
	int answer;
public:
	SolveQuestion() : x_s(0), y_s(0), x_e(0), y_e(0), answer(0)
	{

	}
	void input()
	{
		scanf("%d %d %d %d", &x_s, &y_s, &x_e, &y_e);
	}
	void calAnswer(int x, int y, int r)
	{
		bool start = false;
		bool end = false;

		if ((x_s - x) * (x_s - x) + (y_s - y) * (y_s - y) < r * r)
		{
			start = true;
		}
		if ((x_e - x) * (x_e - x) + (y_e - y) * (y_e - y) < r * r)
		{
			end = true;
		}
		if (start && end)
		{
			return;
		}
		else if (start||end)
		{
			answer++;
			return;
		}
	}
	void printAnswer()
	{
		printf("%d\n", answer);
	}
};


int main(void)
{
	int testcase = 0;
	int planet_count = 0;
	int x = 0;
	int y = 0;
	int r = 0;

	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++)
	{
		SolveQuestion *solveQuestion = new SolveQuestion();
		solveQuestion->input();
		scanf("%d", &planet_count);
		for (int n = 1; n <= planet_count; n++)
		{
			scanf("%d %d %d", &x, &y, &r);
			solveQuestion->calAnswer(x, y, r);
		}
		solveQuestion->printAnswer();

		delete solveQuestion;
	}

	return 0;
}