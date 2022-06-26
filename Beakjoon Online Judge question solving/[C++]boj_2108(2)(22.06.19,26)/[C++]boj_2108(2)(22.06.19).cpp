#include<iostream>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

class Num
{
public:
	Num(int input_num_count);
	~Num();
	void inputNum(int input_num);
	void mergeSort(int min, int max);
	void printAnswer();

private:
	int *num;
	int *sortNum;
	int num_index;
	int sum;
	int num_count;
	int countNumber[8001];
	int minNum;
	int maxNum;
};

Num::Num(int input_num_count) : num_index(0), sum(0), num_count(input_num_count), minNum(9999), maxNum(-9999), countNumber{0}
{
	num = new int[num_count];
	sortNum = new int[num_count];
}

Num::~Num()
{
	delete []num;
	delete []sortNum;
}

void Num::inputNum(int input_num)
{
	if(num_index >= num_count)
	{
		cout<<"인덱스 초과 에러"<<endl;
		return;
	}
	num[num_index] = input_num;
	num_index++;
	sum += input_num;
	countNumber[input_num+4000]++;
	
	if(input_num < minNum)
	{
		minNum = input_num;
	}
	if(input_num > maxNum)
	{
		maxNum = input_num;
	}
}

void Num::mergeSort(int start, int end)
{
	if(start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	
	int i = start;
	int j = mid + 1;
	int k = start;
	
	for(k=start; k<=end; k++)
	{
		if(num[i] <= num[j])
		{
			sortNum[k] = num[i++];
		}
		else
		{
			sortNum[k] = num[j++];
		}
		if(i>mid || j>end)
		{
			k++;
			break;
		}
	}
	if(i>mid)
	{
		for(; k<=end; k++)
		{
			sortNum[k] = num[j++];
		}
	}
	else if(j>end)
	{
		for(; k<=end; k++)
		{
			sortNum[k] = num[i++];
		}
	}
	else
	{
		cout<<"정렬 오류"<<endl;
		return;
	}
	
	for(int k=start; k<=end; k++)
	{
		num[k] = sortNum[k];
	}
	
	return;
}

void Num::printAnswer()
{
	int maxCountNumber = 0;
	int maxCountNumber_num = -4001;
	int average = round(sum/(double)num_index);
	bool nest = true;
	
	//1. 산술평균
	//cout<<"1. 산술평균 : ";
	cout<<average<<endl;
	//2. 중앙값
	//cout<<"2. 중앙값 : ";
	mergeSort(0, num_index - 1);
	cout<<num[num_index/2]<<endl;
	/*cout<<"정렬값 확인"<<endl;
	for(int i=0; i<num_index; i++)
	{
		cout<<num[i]<<endl;
	}
	cout<<"정렬값 확인 끝"<<endl;*/
	//3. 최빈값 
	//cout<<"3. 최빈값 : "; 
	for(int i=0; i<=8000; i++)
	{
		if(countNumber[i] > maxCountNumber)
		{
			maxCountNumber = countNumber[i];
			maxCountNumber_num = i - 4000;
			nest = false;
			//cout<<"현재 최빈값 : "<<maxCountNumber_num<<endl;
		}
		else if(countNumber[i] == maxCountNumber && nest == false)
		{
			maxCountNumber_num = i - 4000;
			nest = true;
			//cout<<"현재 최빈값 : "<<maxCountNumber_num<<endl;
		}
	}
	cout<<maxCountNumber_num<<endl;
	//4. 범위
	//cout<<"4. 범위 : ";
	cout<<maxNum - minNum<<endl; 
}

int main(void)
{
	int N = 0;
	int input = 0;
	
	cin>>N;
	Num test(N);
	for(int i=0; i<N; i++)
	{
		cin>>input;
		test.inputNum(input);
	}
	test.printAnswer();
	cin>>N;
}





































