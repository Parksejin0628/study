//Number of Question : 1931
//Difficulty : Silver 2
//Time to solve : 57m 32s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

void mergeSort(int start, int end);

int meetingTime[100010][2]={0};
int sortedTime[100010][2]={0};

void mergeSort(int start, int end)
{
	if(start>=end)	return;
	//printf("start : %d, end : %d\n",start,end);
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	int a=start;
	int b=mid+1;
	int c=start;
	//printf("start : %d, end : %d, a : %d, b : %d\n",start,end,a,b);
	for(;c<=end ; c++)
	{
		if(a>mid || b>end)	break;
		if(meetingTime[a][1] > meetingTime[b][1])
		{
			sortedTime[c][0] = meetingTime[b][0];
			sortedTime[c][1] = meetingTime[b][1];
			//printf("check1 %d, %d 비교 후 %d위치에 %d %d정렬\n",a+1,b+1,c+1,sortedTime[c][0], sortedTime[c][1]);
			b++;
		}
		else if(meetingTime[a][1] < meetingTime[b][1])
		{
			sortedTime[c][0] = meetingTime[a][0];
			sortedTime[c][1] = meetingTime[a][1];
			//printf("check2 %d, %d 비교 후 %d위치에 %d %d정렬\n",a+1,b+1,c+1,sortedTime[c][0], sortedTime[c][1]);
			a++;
			}
		else
		{
			if(meetingTime[a][0] > meetingTime[b][0])
			{
				sortedTime[c][0] = meetingTime[b][0];
				sortedTime[c][1] = meetingTime[b][1];
			//	printf("check3 %d, %d 비교 후 %d위치에 %d %d정렬\n",a+1,b+1,c+1,sortedTime[c][0], sortedTime[c][1]);
				b++;
			}
			else if(meetingTime[a][0] < meetingTime[b][0])
			{
				sortedTime[c][0] = meetingTime[a][0];
				sortedTime[c][1] = meetingTime[a][1];
			//	printf("check4 %d, %d 비교 후 %d위치에 %d %d정렬\n",a+1,b+1,c+1,sortedTime[c][0], sortedTime[c][1]);
				a++;
			}
			else
			{
				sortedTime[c][0] = meetingTime[a][0];
				sortedTime[c][1] = meetingTime[a][1];
			//	printf("check5 %d, %d 비교 후 %d위치에 %d %d정렬\n",a+1,b+1,c+1,sortedTime[c][0], sortedTime[c][1]);
				a++;
			}
		}
	}
	if(a>mid)
	{
		for(; c<=end ; c++)
		{
			sortedTime[c][0] = meetingTime[b][0];
			sortedTime[c][1] = meetingTime[b][1];
			b++;
		}
	}
	else if(b>end)
	{
		for(; c<=end ; c++)
		{
			sortedTime[c][0] = meetingTime[a][0];
			sortedTime[c][1] = meetingTime[a][1];
			a++;
		}
	}
	
	for(int i=start ; i<=end ; i++)
	{
		meetingTime[i][0] = sortedTime[i][0];
		meetingTime[i][1] = sortedTime[i][1];
	}
	
	return;
}

int main(void)
{
	int n=0;
	int acount=0;
	int lastTime=0;
	
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++)
	{
		scanf("%d %d",&meetingTime[i][0], &meetingTime[i][1]);
	}
	mergeSort(0, n-1);
	/*for(int i=0 ; i<n ; i++)
	{
		printf("sortedTime : %d %d\n",sortedTime[i][0], sortedTime[i][1]);
	}*/
	for(int i=0 ; i<n ; i++)
	{
		if(lastTime <= sortedTime[i][0])
		{
			lastTime = sortedTime[i][1];
			acount++;
		}
	}
	
	printf("%d",acount);
	
	return 0;
}
