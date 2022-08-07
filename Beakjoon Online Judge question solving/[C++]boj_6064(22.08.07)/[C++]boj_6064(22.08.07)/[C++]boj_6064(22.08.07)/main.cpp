#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int testcase, M, N, x, y;
	bool answer = false;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> M >> N >> x >> y;
		for (int i = 0; i <= N; i++)
		{
			if ((M * i + x) % N == y % N)
			{
				cout << M * i + x << endl;
				answer = true;
				break;
			}
		}
		if (!answer)
		{
			cout << "-1" << endl;
		}
		answer = false;
	}

	return 0;
}