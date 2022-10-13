#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

int count[2] = { 0, 0 };

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		count[0]++;
		return 1;
	}
	else
	{
		return (fib(n - 1) + fib(n - 2));
	}
}

int fibonacci(int n)
{
	int* f = new int[n+1];
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		count[1]++;
	}
	return f[n];
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	fib(n);
	fibonacci(n);
	printf("%d %d", count[0], count[1]);
}