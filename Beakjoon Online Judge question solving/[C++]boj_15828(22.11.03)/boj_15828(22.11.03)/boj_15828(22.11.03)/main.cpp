#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

int buffer[100100] = { 0 };

int main(void)
{
	int n = 0;
	int frontIndex = 0;
	int rearIndex = 0;
	int input = 0;

	scanf("%d", &n);
	n++;
	while (input != -1)
	{
		scanf("%d", &input);
		if (input == -1)
		{
			break;
		}
		else if (input == 0)
		{
			if (frontIndex != rearIndex)
			{
				frontIndex = (frontIndex + 1) % n;
			}
		}
		else if (input > 0)
		{
			if ((rearIndex+1)%n != frontIndex)
			{
				buffer[rearIndex] = input;
				rearIndex = (rearIndex + 1) % n;
			}
		}
	}
	if (rearIndex  == frontIndex)
	{
		printf("empty");
	}
	else if (rearIndex < frontIndex)
	{
		for (int i = frontIndex; i < n; i++)
		{
			printf("%d ", buffer[i]);
		}
		for (int i = 0; i < rearIndex; i++)
		{
			printf("%d ", buffer[i]);
		}
	}
	else
	{
		for (int i = frontIndex; i < rearIndex; i++)
		{
			printf("%d ", buffer[i]);
		}
	}

	return 0;
}