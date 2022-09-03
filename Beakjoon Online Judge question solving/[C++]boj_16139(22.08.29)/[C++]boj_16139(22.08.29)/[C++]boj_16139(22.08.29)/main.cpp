#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable: 4996)

using std::cin;
using std::cout;
using std::endl;


void mergeSort(int start, int end, char* arr1, char* arr2)
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

	while (start <= end)
	{
		mid = (start + end) / 2;
		//cout << "check" << endl;
		//cout << "찾는 숫자 : " << num << endl;
		//cout << "현재 체크 : " << arr[mid] << endl;
		if (num < arr[mid])
		{
			end = mid - 1;
		}
		else if (num > arr[mid])
		{
			start = mid + 1;
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
	int wordCount = 0;
	int searchCount = 0;
	char* words;
	char* sortedArr;
	char searchWord[500];

	scanf("%d %d", &wordCount, &searchCount);

	words = new char[wordCount];
	sortedArr = new char[wordCount];

	for (int i = 0; i < wordCount; i++)
	{
		scanf("%s", words[i]);
	}
	mergeSort(0, wordCount - 1, words, sortedArr);
	for (int i = 0; i < searchCount; i++)
	{
		scanf("%s", searchWord);
	}


	return 0;
}
