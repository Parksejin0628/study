#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable: 4996)

using std::cin;
using std::cout;
using std::endl;

class Set
{
private:
	int* numbers;
	int* sortedNum;
	int numberCount;

public:
	Set(int count) : numberCount(count)
	{
		numbers = new int[numberCount];
		sortedNum = new int[numberCount];
	}
	void inputNum()
	{
		for (int i = 0; i < numberCount; i++)
		{
			scanf("%d", &numbers[i]);
		}
		mergeSort(0, numberCount - 1);
	}
	void mergeSort(int start, int end)
	{
		if (start >= end)	return;
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		int i = start;
		int j = mid + 1;
		int k = start;

		for (; k <= end; k++)
		{
			if (i > mid || j > end)	break;
			if (numbers[i] < numbers[j])
			{
				sortedNum[k] = numbers[i++];
			}
			else
			{
				sortedNum[k] = numbers[j++];
			}
		}
		if (i > mid)
		{
			for (; k <= end; k++)
			{
				sortedNum[k] = numbers[j++];
			}
		}
		else
		{
			for (; k <= end; k++)
			{
				sortedNum[k] = numbers[i++];
			}
		}
		for (k = start; k <= end; k++)
		{
			numbers[k] = sortedNum[k];
		}

		return;
	}
	void showSet()
	{
		for (int i = 0; i < numberCount; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				cout << endl;
			}
			cout << numbers[i] << " ";
		}
		cout << endl << endl;
	}
	int compareSet(const Set& other)
	{
		int thisIndex = 0;
		int otherIndex = 0;
		int overlap = 0;
		while (thisIndex < numberCount && otherIndex < other.numberCount)
		{
			if (numbers[thisIndex] == other.numbers[otherIndex])
			{
				//cout << "check : " << thisIndex << " " << otherIndex << endl;
				overlap++;
				thisIndex++;
				otherIndex++;
			}
			else if (numbers[thisIndex] < other.numbers[otherIndex])
			{
				thisIndex++;
			}
			else if (numbers[thisIndex] > other.numbers[otherIndex])
			{
				otherIndex++;
			}
		}
		
		//cout << "numberCount + other.numberCount = " << numberCount + other.numberCount << endl;
		//cout << "overlap * 2 = " << overlap * 2 << endl;
		return (numberCount + other.numberCount - (overlap * 2));
	}
	~Set()
	{
		delete[]numbers;
		delete[]sortedNum;
	}
};

int main(void)
 {
	int set1Count = 0;
	int set2Count = 0;

	scanf("%d %d", &set1Count, &set2Count);

	Set set1(set1Count);
	Set set2(set2Count);

	set1.inputNum();
	set2.inputNum();
	//set1.showSet();
	//set2.showSet();
	printf("%d",set1.compareSet(set2));

	return 0;
}