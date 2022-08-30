#include<iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

void mergeSort(int start, int end, int* arr1, int* arr2)
{
	if (!(start < end))
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid, arr1, arr2);
	mergeSort(mid + 1, end, arr1, arr2);
	int i = start;
	int j = mid + 1;
	int k = start;

	for (; k <= end; k++)
	{
		if (i > mid || j > end)
		{
			break;
		}
		if (arr1[i] > arr1[j])
		{
			arr2[k] = arr1[j++];
		}
		else
		{
			arr2[k] = arr1[i++];
		}
	}
	if (i > mid)
	{
		for (; k <= end; k++)
		{
			arr2[k] = arr1[j++];
		}
	}
	else if(j > end)
	{
		for (; k <= end; k++)
		{
			arr2[k] = arr1[i++];
		}
	}
	else
	{
		cout << "error!" << endl;
		return;
	}
	for (k = start; k <= end; k++)
	{
		arr1[k] = arr2[k];
	}

}

bool binarySearch(int num, int* arr, int arrSize)
{
	int start = 0;
	int end = arrSize - 1;
	int mid = (start + end) / 2;

	while (start < end)
	{
		//cout << "check" << endl;
		//cout << "찾는 숫자 : " << num << endl;
		//cout << "현재 체크 : " << arr[mid] << endl;
		if (num < arr[mid])
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (num > arr[mid])
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else if (num == arr[mid])
		{
			return true;
		}
		else
		{
			cout << "error!" << endl;
		}
	}
	return false;
}

int main(void)
{
	int cardCount = 0;
	int* card;
	int* sortArr;
	int searchCount = 0;
	int searchNum = 0;

	cin >> cardCount;
	card = new int[cardCount];
	sortArr = new int[cardCount];

	for (int i = 0; i < cardCount; i++)
	{
		cin >> card[i];
	}
	mergeSort(0, cardCount - 1, card, sortArr);
	/*cout << "[정렬 후 배열]" << endl;
	for (int i = 0; i < cardCount; i++)
	{
		cout << card[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl << endl;*/
	cin >> searchCount;
	for (int i = 0; i < searchCount; i++)
	{
		cin >> searchNum;
		cout << binarySearch(searchNum, card, cardCount)<<" ";
	}

	return 0;
}