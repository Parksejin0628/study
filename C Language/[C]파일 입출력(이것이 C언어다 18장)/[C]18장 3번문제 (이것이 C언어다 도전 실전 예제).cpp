#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int score_kor;
	int score_math;
	int score_eng;
	int num;
	int sum;
	char name[20];
}Grade;

void inputGrade(Grade *students);
void printStudents(Grade *students);
void sortStudents(Grade *students);

int main(void)
{
	Grade students[5] = {0};
	
	inputGrade(students);
	printf("\n# 정렬 전 데이터...\n");
	printStudents(students);
	sortStudents(students);
	printf("\n# 정렬 후 데이터...\n");
	printStudents(students);
	
	scanf("%d");
	
	return 0;
}

void inputGrade(Grade *students)
{
	int i=0;
	
	for(i=0; i<5; i++)
	{
		printf("학번 : ");
		scanf("%d", &students[i].num);
		printf("이름 : ");
		scanf("%s", students[i].name);
		printf("국어, 영어, 수학 점수 : ");
		scanf("%d %d %d", &students[i].score_kor, &students[i].score_math, &students[i].score_eng);
		students[i].sum = students[i].score_kor + students[i].score_eng + students[i].score_math;
	}
	
	return;
}

void printStudents(Grade *students)
{
	int i = 0;
	double avg = 0;
	char grade = '\0';
	
	for(i=0; i<5; i++)
	{
		avg = students[i].sum / 3.0;
		if(avg >= 90)
		{
			grade = 'A';
		}
		else if(avg >= 80)
		{
			grade = 'B';
		}
		else if(avg >= 70)
		{
			grade = 'C';
		}
		else
		{
			grade = 'F';
		}
		printf("%d %s%5d%5d%5d%5d%5.1lf%5c\n", students[i].num, students[i].name, students[i].score_kor, students[i].score_eng, students[i].score_math, students[i].sum, avg, grade);
	}
	
	return;
}

void sortStudents(Grade *students)
{
	int i = 0;
	int j = 0;
	Grade temp;
	
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(students[i].sum < students[j].sum)
			{
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
	
	return;
}


/*
도전 3 성적 처리 프로그램
 - 학생 다섯 명의 국어, 영어, 수학 점수를 입력하여 총점, 평균, 학점을 구하고 총점 순으로 정렬하여 출력합니다.
   학점은 평균이 90점 이상이면 A, 80점 이상이면 B, 70점 이상이며녀 C, 그 외에는 F로 평가합니다. 
*/ 
