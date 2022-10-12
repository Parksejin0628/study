#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

typedef struct Position
{
	int x;
	int y;
}position;

class SolvingQuestion
{
private:
	int X, Y, W, H, R, P;
	int answer;
	position center[2];
public:
	SolvingQuestion() : X(0), Y(0), W(0), H(0), R(0), P(0), answer(0)
	{
		center[0] = { 0, 0 };
		center[1] = { 0, 0 };
	}
	void input()
	{
		scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);
		R = H / 2;
		center[0] = { X, Y + R };
		center[1] = { X + W, Y + R };
	}
	void inputPosition()
	{
		position temp;
		for (int i = 1; i <= P; i++)
		{
			scanf("%d %d", &temp.x, &temp.y);
			calAnswer(temp);
		}
	}
	void calAnswer(position temp)
	{
		if (X <= temp.x && temp.x < +X + W && Y <= temp.y && temp.y <= Y + H)
		{
			//cout << "check F : calAnswer / first" << endl;
			answer++;
		}
		else if ((temp.x - center[0].x) * (temp.x - center[0].x) + (temp.y - center[0].y) * (temp.y - center[0].y) <= R * R)
		{
			//cout << "check F : calAnswer / second" << endl;
			answer++;
		}
		else if ((temp.x - center[1].x) * (temp.x - center[1].x) + (temp.y - center[1].y) * (temp.y - center[1].y) <= R * R)
		{
			//cout << "check F : calAnswer / third" << endl;
			answer++;
		}
	}
	void printAnswer()
	{
		printf("%d\n", answer);
	}
};

int main(void)
{
	SolvingQuestion solvingQuestion;
	solvingQuestion.input();
	solvingQuestion.inputPosition();
	solvingQuestion.printAnswer();

	return 0;
}