#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int counting = 0;
int nowcounting = 0;

// pop���� �� ��ȯ�� �� �ڽ� �� �� �� ū �ڽİ� ��ȯ�ϴ� ���� �ؾߵȴ�.

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
	void printData()
	{
		cout << num << "(" << deleteCheck << ")";
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
	bool dataEmpty;
public:
	DoublePriorityQueue() : rearIndex_maxQueue(1), rearIndex_minQueue(1), parentIndex(0), childIndex(0)
	, newData(NULL), temp_swap(NULL), maxQueue{}, minQueue{}, dataEmpty(true)
	{ }
	void inputNewData(int input)
	{
		nowcounting = counting;
		newData = new Data(input);
		dataEmpty = false;
		//maxQueue
		childIndex = rearIndex_maxQueue;
		parentIndex = childIndex / 2;
		maxQueue[rearIndex_maxQueue++] = newData;
		while (parentIndex > 0)
		{
			//testcode
			counting++;
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
			counting++;
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
		//cout << "���� ���� �� : " << rearIndex_maxQueue << endl;
		//cout << "���⵵ : " << counting - nowcounting<<endl;
		//cout << "������ �Է� �� " << endl;
		//printArr();

		return;
	}
	int maxPop(bool del)
	{
		if (dataEmpty)
		{
			return -1;
		}
		Data* popData = maxQueue[1];
		int retNum = popData->getNum();
		
		nowcounting = counting;
		while(rearIndex_maxQueue>1)
		{
			popData = maxQueue[1];
			retNum = popData->getNum();
			maxQueue[1] = maxQueue[--rearIndex_maxQueue];
			if (rearIndex_maxQueue <= 1 && del == true)
			{
				dataEmpty = true;
			}
			parentIndex = 1;
			childIndex = parentIndex * 2;
			while (childIndex < rearIndex_maxQueue)
			{
				counting++;
				if (childIndex + 1 < rearIndex_maxQueue && maxQueue[childIndex]->getNum() < maxQueue[childIndex + 1]->getNum())
				{
					childIndex++;
				}
				if (maxQueue[parentIndex]->getNum() < maxQueue[childIndex]->getNum())
				{
					temp_swap = maxQueue[parentIndex];
					maxQueue[parentIndex] = maxQueue[childIndex];
					maxQueue[childIndex] = temp_swap;
					parentIndex = childIndex;
					childIndex = parentIndex * 2;
				}
				else
				{
					break;
				}
			}
			
			
			if (popData->deleteData(del))
			{
				//cout << "maxPop���� ��(�ѹ� ��)" << endl;
				//printArr();
				delete popData;
				popData = NULL;
				continue;
			}
			//cout << "maxPop���� ��(����)" << endl;
			//printArr();
			break;
		}
		//cout << "���� ���� �� : " << rearIndex_maxQueue << endl;
		//cout << "���⵵ : " << counting - nowcounting << endl;
		if (popData == NULL && del == false)
		{
			dataEmpty = true;
		}
		return retNum;
	}

	int minPop(bool del)
	{
		if (dataEmpty)
		{
			return -1;
		}
		Data* popData = minQueue[1];
		int retNum = popData->getNum();
		nowcounting = counting;
		while(rearIndex_minQueue > 1)
		{
			popData = minQueue[1];
			retNum = popData->getNum();
			minQueue[1] = minQueue[--rearIndex_minQueue];
			if (rearIndex_minQueue <= 1 && del == true )
			{
				dataEmpty = true;
			}
			parentIndex = 1;
			childIndex = parentIndex * 2;

			while (childIndex < rearIndex_minQueue)
			{
				counting++;
				if (childIndex + 1 < rearIndex_minQueue && minQueue[childIndex]->getNum() > minQueue[childIndex + 1]->getNum())
				{
					childIndex++;
				}
				if (minQueue[parentIndex]->getNum() > minQueue[childIndex]->getNum())
				{
					temp_swap = minQueue[parentIndex];
					minQueue[parentIndex] = minQueue[childIndex];
					minQueue[childIndex] = temp_swap;
					parentIndex = childIndex;
					childIndex = parentIndex * 2;
				}
				else
				{
					break;
				}
			}
			if (popData->deleteData(del))
			{
				delete popData;
				popData = NULL;
				//cout << "minPop���� ��(�ѹ� ��)" << endl;
				//printArr();
				continue;
			}
			//cout << "minPop���� ��(����)" << endl;
			//printArr();
			break;
		}
		//cout << "���� ���� �� : " << rearIndex_maxQueue << endl;
		//cout << "���⵵ : " << counting - nowcounting << endl;
		if (popData == NULL && del == false)
		{
			dataEmpty = true;
		}
		return retNum;
	}
	void printAnswer()
	{
		//cout << "���� �迭����" << endl;
		//printArr();
		int max = maxPop(false);
		int min = minPop(false);

		if (dataEmpty)
		{
			cout << "EMPTY" << endl;
		}
		else
		{
			cout << max << " " << min << endl;
		}
		//cout << "���� Ƚ�� : " << counting << endl;
		

		return;
	}
	void printArr()
	{
		cout << "maxQueue" << endl;
		for (int i = 1; i < rearIndex_maxQueue; i++)
		{
			maxQueue[i]->printData();
			cout << " ";
		}
		cout << endl << "minQueue" << endl;
		for (int i = 1; i < rearIndex_minQueue; i++)
		{
			minQueue[i]->printData();
			cout << " ";
		}
		cout << endl << endl;
	}
};

int main(void)
{
	int testcase = 0;
	int commandcase = 0;
	char command = '\0';
	int inputNum = 0;
	DoublePriorityQueue* doublePriorityQueue = new DoublePriorityQueue;

	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> commandcase;
		for (int k = 1; k <= commandcase; k++)
		{
			cin >> command >> inputNum;
			if (command == 'I')
			{
				doublePriorityQueue->inputNewData(inputNum);
			}
			else if (command == 'D')
			{
				if (inputNum == 1)
				{
					doublePriorityQueue->maxPop(true);
				}
				else if (inputNum == -1)
				{
					doublePriorityQueue->minPop(true);
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
		doublePriorityQueue->printAnswer();
		delete doublePriorityQueue;
		doublePriorityQueue = new DoublePriorityQueue;
	}

	return 0;
}