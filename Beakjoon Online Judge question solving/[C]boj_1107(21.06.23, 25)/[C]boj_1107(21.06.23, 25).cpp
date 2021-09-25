//number of question : 1107
//Difficulty : Gold 5
//Time to solve : 1h 35m 43s 
//Simple review : 

#include<stdio.h>

int checkDigits(int num);
//int calApproximate(int num, int digits, int min, int max);
int calApproximate(int num);
int checkButton(int num);

int brokenButton[10] = {0};

int main(void)
{
	int n = 0;
	int m = 0;
	int num = 0;
	int min = 10;
	int max = -1;
	int digits = 0;
	int diff = 0;
	int temp = 0;
	
	scanf("%d",&n);
	if(n >= 100)
	{
		diff = n - 100;
	}
	else
	{
		diff = 100 - n;
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d",&num);
		brokenButton[num] = 1;
	}
	if(m == 10)
	{
		printf("%d\n", diff);
		scanf("%d",&n);
		
		return 0;
	} 
/*	for(int i=0; i<=9; i++)
	{
		if(i < min)
		{
			min = i;
		}
		if(i > max)
		{
			max = i;
		}
	}*/
	digits = checkDigits(n);
	//printf("check1 - digits : %d\n", digits);
	//temp = calApproximate(n, digits, min, max);
	temp = calApproximate(n);
	/*
	if(temp + digits < diff && temp >= 0)
	{
		diff = temp + digits;
	}
	*/
	if(temp < diff)
	{
		diff = temp;
	}
	
	printf("%d\n", diff);
	scanf("%d",&n);
	
	return 0;
}

int checkDigits(int num)
{
	if(num < 0)	return -1;
	int digits = 1;
	int temp = 10;
	
	while(num >= temp)
	{
		digits++;
		temp *= 10;
	}
	return digits;
}

/*
int calApproximate(int num, int digits, int min, int max)
{
	int temp = 1;
	int digitNum = 0;
	int high = 1;
	int low = 9;
	int highApp = 0;
	int lowApp = 0;
	int diffHigh = 0;
	int diffLow = 0;
	
	for(int i=1; i<digits; i++)
	{
		temp *= 10;
	}
	for(; digits>=1; digits--)
	{
		digitNum = (num/temp) % 10;
		printf("check4 - digits : %d, digitNum : %d, temp : %d\n", digits, digitNum, temp);
		if(brokenButton[digitNum] == 0)
		{
			highApp += digitNum * temp;
			lowApp += digitNum * temp;
			temp /= 10;
		}
		else
		{
			for(int i=digitNum+1; i<=9; i++)
			{
				if(brokenButton[i] == 0)
				{
					high = i;
					break;
				}
			}
			for(int i=digitNum-1; i>=0; i--)
			{
				if(brokenButton[i] == 0)
				{
					low = i;
					break;
				}
			}
			printf("check5 - high : %d, low : %d\n", high, low);
			highApp += high * temp;
			lowApp += low * temp;
			for(int i=digits-1; i>=1; i--)
			{
				temp /= 10;
				highApp += min * temp;
				lowApp += max * temp;
			}
			diffHigh = highApp - num;
			diffLow = num - lowApp;
			break;
		}
	}
	printf("check2 - num : %d, diffHigh : %d, diffLow : %d\n", num, diffHigh, diffLow);
	printf("check3 - highApp : %d, lowApp : %d\n", highApp, lowApp);
	if(diffHigh < diffLow)
	{
		return diffHigh;
	}
	else
	{
		return diffLow;
	}
}
*/
int calApproximate(int num)
{
	int highApp = num;
	int lowApp = num;
	int highDiff = -1;
	int lowDiff = -1;
	int find = 0;
	
	while(find == 0)
	{
		if(checkButton(highApp) == 1)
		{
			highDiff = highApp - num + checkDigits(highApp);
			find = 1;
		}
		if(lowApp >= 0 && checkButton(lowApp) == 1)
		{
			lowDiff = num - lowApp + checkDigits(lowApp);
			find = 1;
		}
		if(find == 0)
		{
			highApp++;
			lowApp--;
		}
	}
	if(lowDiff == -1)	return highDiff;
	else if(highDiff == -1)	return lowDiff;
	else
	{
		if(highDiff < lowDiff)	return highDiff;
		else	return lowDiff;
	}
}

int checkButton(int num)
{
	int digits = checkDigits(num);
	int temp = 1;
	int digitNum = 0;
	for(int i=1; i<digits; i++)
	{
		temp *= 10;
	}
	for(; digits>=1; digits--)
	{
		digitNum = (num/temp) % 10;
		if(brokenButton[digitNum] == 1)
		{
			return -1;
		}
		temp /= 10;
	}
	return 1;
}
