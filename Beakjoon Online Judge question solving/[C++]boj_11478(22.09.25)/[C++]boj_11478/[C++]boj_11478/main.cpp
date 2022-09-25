#include<iostream>
#include<cstdio>
#include<cstring>

class Str
{
private:
	char* str;
	char* str_part;
	int str_part_length;
public:
	Str(const char* input) : str_part_length(0)
	{
		str = new char[strlen(input)];
		str_part = new char[strlen(input) * strlen(input)];
		strcpy(str, input);
	}
	~Str()
	{
		delete[]str;
		delete[]str_part;
	}
	void selectStr()
	{

	}
	void mergeSort(int start, int end)
	{

	}
	void count_unique()
	{

	}
};

int main(void)
{


	return 0;
}