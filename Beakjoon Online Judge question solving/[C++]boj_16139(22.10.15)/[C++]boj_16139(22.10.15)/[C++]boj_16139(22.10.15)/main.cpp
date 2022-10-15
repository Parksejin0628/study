#include<iostream>
#include<cstdio>
#include<cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class SolvingQuestion
{
private:
	char* sentence;
	int sentence_length;
	int** count_alphabet;
public:
	SolvingQuestion() : sentence_length(0)
	{
		sentence = new char[200100];
		count_alphabet = new int* [26];
		for (int i = 0; i < 26; i++)
		{
			count_alphabet[i] = new int[200100];
		}
	}
	~SolvingQuestion()
	{
		delete[]sentence;
		for (int i = 0; i < 26; i++)
		{
			delete[]count_alphabet[i];
		}
		delete[]count_alphabet;
	}
	void inputSentence()
	{
		scanf("%s", sentence);
		sentence_length = strlen(sentence);
	}
	void countAlphabet()
	{
		for (int i = 0; i < sentence_length; i++)
		{
			if (sentence[i] - 'a' < 0 || sentence[i] - 'a' > 26)
			{
				cout << "인덱스 : " << i << " 문자 : " << sentence[i];
				cout << "범위 오류" << endl;
				break;
			}
			if (i == 0)
			{
				for (int j = 0; j < 26; j++)
				{
					if (sentence[i] - 'a' == j)
					{
						count_alphabet[j][i] = 1;
					}
					else
					{
						count_alphabet[j][i] = 0;
					}
				}
			}
			else
			{
				for (int j = 0; j < 26; j++)
				{
					if (sentence[i] - 'a' == j)
					{
						count_alphabet[j][i] = count_alphabet[j][i - 1] + 1;
					}
					else
					{
						count_alphabet[j][i] = count_alphabet[j][i - 1];
					}
				}
			}
			/*printf("[%d]\n", i);
			for (int j = 0; j < 26; j++)
			{
				printf("%c : %d    ", 'a' + j,  count_alphabet[j][i]);
				if ((j+1) % 10 == 0)
				{
					//printf("\n");
				}
			}
			printf("\n");*/
		}
	}
	void printAnswer(char alphabet, int start, int end)
	{
		if (start == 0)
		{
			printf("%d\n", count_alphabet[alphabet-'a'][end]);
			return;
		}
		printf("%d\n", count_alphabet[alphabet - 'a'][end] - count_alphabet[alphabet - 'a'][start - 1]);
	}
};

int main(void)
{
	int questionCount = 0;
	int section_start = 0;
	int section_end = 0;
	char alphabet;
	SolvingQuestion solvingQuestion;
	solvingQuestion.inputSentence();
	solvingQuestion.countAlphabet();
	scanf("%d", &questionCount);
	for (int i = 0; i < questionCount; i++)
	{
		//cout << "check : " << i <<" questionCount : "<< questionCount << endl;
		fgetc(stdin);
		scanf("%c %d %d", &alphabet, &section_start, &section_end);
		//cout << "checkScanf / alphabet " <<alphabet << " section : " << section_start << " " << section_end << endl;
		solvingQuestion.printAnswer(alphabet, section_start, section_end);
	}

	return 0;
}