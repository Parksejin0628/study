#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable: 4996)

class MergeSort
{
private:
	int* arr;
	int* temp;
	int arr_size;
	int save_count;
	int target;
public:
	MergeSort(int arr_size, int k) : arr_size(arr_size), save_count(0), target(k)
	{
		arr = new int[arr_size];
		temp = new int[arr_size];
	}
	~MergeSort()
	{
		if (save_count < target)
		{
			printf("-1\n");
		}
		delete[]arr;
		delete[]temp;
	}
	void inputArr()
	{
		for (int i = 0; i < arr_size; i++)
		{
			scanf("%d", &arr[i]);
		}
	}
	void mergeSort(int start, int end)
	{
		if (start >= end)
		{
			return;
		}
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		int i = start;
		int j = mid + 1;
		int k = start;

		for (; k <= end; k++)
		{
			if (i > mid || j > end)
			{
				break;
			}
			if (arr[i] <= arr[j])
			{
				temp[k] = arr[i++];
			}
			else
			{
				temp[k] = arr[j++];
			}
		}
		if (i > mid)
		{
			for (; k <= end; k++)
			{
				temp[k] = arr[j++];
			}
		}
		else
		{
			for (; k <= end; k++)
			{
				temp[k] = arr[i++];
			}
		}
		for (k = start; k <= end; k++)
		{
			save_count++;
			if (save_count == target)
			{
				printf("%d\n", temp[k]);
			}
			arr[k] = temp[k];
		}
	}
};

int main(void)
 {
	int arr_size;
	int k;
	scanf("%d %d", &arr_size, &k);

	MergeSort mergeSort(arr_size, k);
	mergeSort.inputArr();
	mergeSort.mergeSort(0, arr_size - 1);

	return 0;
}