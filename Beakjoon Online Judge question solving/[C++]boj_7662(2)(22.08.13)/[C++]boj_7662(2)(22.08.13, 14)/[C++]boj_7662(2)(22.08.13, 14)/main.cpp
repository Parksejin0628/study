#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Data
{
private:
	int num;
	bool deleteCheck;
public:
	Data() : num(0), deleteCheck(false) { }
	Data(int inputNum) : num(inputNum), deleteCheck(false) { }
	void operator=(int inputNum)
	{
		num = inputNum;
	}
	bool deleteData(bool del)
	{
		if (deleteCheck == false)
		{
			if (del)
			{
				deleteCheck = true;
			}
			return false;
		}
		else if (deleteCheck == true)
		{
			return true;
		}
	}
	int getNum()
	{
		return num;
	}
};

class DoublePriorityQueue
{
private:
	Data* newData;
	Data* maxQueue[1000100];
	Data* minQueue[1000100];
	Data* temp_swap;
	int rearIndex_maxQueue;
	int rearIndex_minQueue;
	int parentIndex;
	int childIndex;
public:
	DoublePriorityQueue() : rearIndex_maxQueue(1), rearIndex_minQueue(1), parentIndex(0), childIndex(0) { }
	void inputNewData(int input)
	{
		newData = new Data(input);
		//maxQueue
		childIndex = rearIndex_maxQueue;
		parentIndex = childIndex / 2;
		maxQueue[rearIndex_maxQueue++] = newData;
		while (parentIndex > 0)
		{
			if (maxQueue[parentIndex]->getNum() < maxQueue[childIndex]->getNum())
			{
				temp_swap = maxQueue[parentIndex];
				maxQueue[parentIndex] = maxQueue[childIndex];
				maxQueue[childIndex] = temp_swap;
				childIndex = parentIndex;
				parentIndex = childIndex / 2;
			}
			else
			{
				break;
			}
		}
		//minQueue
		childIndex = rearIndex_minQueue;
		parentIndex = childIndex / 2;
		minQueue[rearIndex_minQueue++] = newData;
		while (parentIndex > 0)
		{
			if (minQueue[parentIndex]->getNum() > minQueue[childIndex]->getNum())
			{
				temp_swap = minQueue[parentIndex];
				minQueue[parentIndex] = minQueue[childIndex];
				minQueue[childIndex] = temp_swap;
				childIndex = parentIndex;
				parentIndex = childIndex / 2;
			}
			else
			{
				break;
			}
		}

		return;
	}
	int maxPop(bool del)
	{
		Data* popData = maxQueue[1];
		int retNum = popData->getNum();
		
		maxQueue[1] = maxQueue[rearIndex_maxQueue--];
		parentIndex = 1;
		childIndex = parentIndex * 2;
		while(childIndex < rearIndex_maxQueue)
	}
	int minPop(bool del);
	void init();
	void printAnswer();
};

int main(void)
{
	int testcase = 0;
	int commandcase = 0;
	char command = '\0';
	int inputNum = 0;
	DoublePriorityQueue doublePriorityQueue;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> commandcase;
		for (int k = 1; k <= commandcase; k++)
		{
			cin >> command >> inputNum;
			if (command == 'I')
			{
				doublePriorityQueue.inputNewData(inputNum);
			}
			else if (command == 'D')
			{
				if (inputNum == 1)
				{
					doublePriorityQueue.maxPop(true);
				}
				else if (inputNum == -1)
				{
					doublePriorityQueue.minPop(true);
				}
				else
				{
					cout << "inputNumError" << endl;
					return 0;
				}
			}
			else
			{
				cout << "CommandError" << endl;
				return 0;
			}
		}
		doublePriorityQueue.printAnswer();
		doublePriorityQueue.init();
	}

	return 0;
}