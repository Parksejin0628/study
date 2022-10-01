#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable: 4996)

using std::cin;
using std::cout;
using std::endl;

class Str
{
private:
	char* str;
	int str_len;
	char** str_part;
	char** str_temp;
	int str_part_length;
public:
	Str(const char* input) : str_part_length(0)
	{
		str_len = strlen(input);
		str = new char[str_len + 2];
		strcpy(str, input);
		str_part = new char*[(str_len + 1) * (str_len / 2 + 1)];
		str_temp = new char*[(str_len + 1) * (str_len / 2 + 1)];
		//cout << "check / F : Str / mid" << endl;
		selectStr();
		mergeSort(0, str_part_length - 1);
		cout << "모든 부분 문자열 개수 : " << str_part_length << endl;
		for (int i = 0; i < str_part_length; i++)
		{
			cout << str_part[i] << endl;
		}
	}
	~Str()
	{
		delete[]str;
		for (int i = 0; i < str_part_length; i++)
		{
			delete[]str_part[i];
			delete[]str_temp[i];
		}
		delete[]str_part;
		delete[]str_temp;
	}
	void selectStr()
	{
		int temp = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			for (int j = i; j < strlen(str); j++)
			{
				str_part[str_part_length] = new char[str_len + 2];
				str_temp[str_part_length] = new char[str_len + 2];
				//cout << "check / F : selectStr / first" << endl;
				for (int k = i; k <= j; k++)
				{
					str_part[str_part_length][temp++] = str[k];
				}
				str_part[str_part_length][temp] = '\0';
				str_part_length++;
				temp = 0;
				//cout << "check / F : selectStr / final" << endl;
			}
		}
	}
	void mergeSort(int start, int end)
	{
		//cout << "check / F : mergeSort / first" << endl;
		if (start >= end) { return; }
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		int i = start;
		int j = mid + 1;
		int k = start;

		//cout << "check / F : mergeSort / before while" << endl;
		while (i <= mid && j <= end)
		{
			//cout << "check / F : mergeSort / while" << endl;
			if (strcmp(str_part[i], str_part[j]) <= 0)
			{
				strcpy(str_temp[k++],str_part[i++]);
			}
			else
			{
				strcpy(str_temp[k++], str_part[j++]);
			}
		}
		if (i > mid)
		{
			while (j <= end)
			{
				strcpy(str_temp[k++], str_part[j++]);
			}
		}
		else if (j > end)
		{
			while (i <= mid)
			{
				strcpy(str_temp[k++], str_part[i++]);
			}
		}
		for (k = start; k <= end; k++)
		{
			strcpy(str_part[k], str_temp[k]);
		}
	}
	int count_unique()
	{
		int count = 1;
		for (int i = 1; i < str_part_length; i++)
		{
			if (strcmp(str_part[i], str_part[i - 1]) != 0)
			{
				count++;
			}
		}
		return count;
	}
};

int main(void)
{
	char* input = new char[1003];
	cin >> input;

	Str str(input);
	cout << str.count_unique();

	delete[]input;

	return 0;
}