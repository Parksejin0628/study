//Number of question : 2261
//Difficulty : Platinum 2
//Time to solve : 5h 4m 6s
//Simple review : Sooooo hard 

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES

int point[100100][2] = {0};
int sortPoint[100100][2] = {0};
int sortPointY[100100][2] = {0};
int ope1 = 0;
int ope2 = 0;
int ope3 = 0;

void mergesort(int start, int end);
int calMinDist(int start, int end, int mid);
int dist(int index1, int index2);

void mergeSort(int start, int end)
{
	if(start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(start, mid);
	mergeSort(mid+1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	for(k=start; k<=end; k++)
	{
		ope1++;
		if(i>mid || j>end)
		{
			break;
		}
		if(point[i][0] <= point[j][0])
		{
			sortPoint[k][0] = point[i][0];
			sortPoint[k][1] = point[i][1];
			i++;
		}
		else
		{
			sortPoint[k][0] = point[j][0];
			sortPoint[k][1] = point[j][1];
			j++;
		}
		//ope++;
	}
	if(i>mid)
	{
		for(; j<=end; j++)
		{
			ope1++;
			sortPoint[k][0] = point[j][0];
			sortPoint[k][1] = point[j][1];
			k++;
			//ope++;
		}
	}
	else
	{
		for(; i<=mid; i++)
		{
			ope1++;
			sortPoint[k][0] = point[i][0];
			sortPoint[k][1] = point[i][1];
			k++;
			//ope++;
		}
	}
	for(i=start; i<=end; i++)
	{
		ope1++;
		//printf("현재 정렬전 값 : point[%d] = %d, %d\n",i, point[i][0], point[i][1]);
		point[i][0] = sortPoint[i][0];
		point[i][1] = sortPoint[i][1];
		//printf("현재 정렬후 값 : point[%d] = %d, %d\n",i, point[i][0], point[i][1]);
		//ope++;
	}
}

void mergeSortY(int start, int end)
{
	if(start == end)
	{
		return;
	}
	int mid = (start + end) / 2;
	mergeSortY(start, mid);
	mergeSortY(mid+1, end);
	int i = start;
	int j = mid + 1;
	int k = start;
	for(k=start; k<=end; k++)
	{
		ope1++;
		if(i>mid || j>end)
		{
			break;
		}
		if(sortPointY[i][1] <= sortPointY[j][1])
		{
			sortPoint[k][0] = sortPointY[i][0];
			sortPoint[k][1] = sortPointY[i][1];
			i++;
		}
		else
		{
			sortPoint[k][0] = sortPointY[j][0];
			sortPoint[k][1] = sortPointY[j][1];
			j++;
		}
		//ope++;
	}
	if(i>mid)
	{
		for(; j<=end; j++)
		{
			ope1++;
			sortPoint[k][0] = sortPointY[j][0];
			sortPoint[k][1] = sortPointY[j][1];
			k++;
			//ope++;
		}
	}
	else
	{
		for(; i<=mid; i++)
		{
			ope1++;
			sortPoint[k][0] = sortPointY[i][0];
			sortPoint[k][1] = sortPointY[i][1];
			k++;
			//ope++;
		}
	}
	for(i=start; i<=end; i++)
	{
		ope1++;
		//printf("현재 정렬전 값 : point[%d] = %d, %d\n",i, point[i][0], point[i][1]);
		sortPointY[i][0] = sortPoint[i][0];
		sortPointY[i][1] = sortPoint[i][1];
		//printf("현재 정렬후 값 : sortPointY[%d] = %d, %d\n",i, sortPointY[i][0], sortPointY[i][1]);
		//ope++;
	}
}

int calMinDist(int start, int end, int mid)
{
	//printf("check5 현재 start, end, mid : %d %d %d\n", start, end, mid);
	if(end - start == 0)
	{
		return 200000000;
	}
	if(end - start == 1)
	{
		return dist(start, end);
	}
	int minL = calMinDist(start, mid-1, (start+mid-1)/2);
	//printf("check6 현재 start, end, mid : %d %d %d\n", start, end, mid);
	int minR = calMinDist(mid+1, end, (mid+end+1)/2);
	//printf("check7 현재 start, end, mid : %d %d %d\n", start, end, mid);
	int min = 0;
	double minRoot = 0;
	int areaLeft = mid;
	int areaRight = mid;
	int temp=0;
	if(minL <= minR)
	{
		min = minL;
	}
	else
	{
		min = minR;
	}
	if(min == 0)	
	{
		printf("0");
		exit(0);
	}
	minRoot = sqrt((double)min);
	//printf("현재 최소거리 : %.3lf\n", minRoot); 
	//printf("check8 현재 start, end, mid : %d %d %d\n", start, end, mid);
	for(int i=mid-1; i>=start; i--)
	{
		ope1++;
		if(point[i][0] < point[mid][0] - minRoot)
		{
			break;
		}
		areaLeft = i;
	}
	for(int i=mid+1; i<=end; i++)
	{
		ope1++;
		if(point[i][0] > point[mid][0] + minRoot)
		{
			break;
		}
		areaRight = i;
	}
	/*for(int i=areaLeft; i<areaRight; i++)
	{
		for(int j=i+1; j<=areaRight; j++)
		{
			if(point[j][0] - point[i][0] > minRoot)
			{
				//printf("%d번째 점과 %d번째 점 사이의 x거리초과: %d\n", i, j, point[j][0] - point[i][0]);
				ope1++;
				break;
			}
			temp = point[j][1] - point[i][1];
			if(temp<0)	temp*=-1;
			if(temp > minRoot)
			{
				ope2++;
				//printf("%d번째 점과 %d번째 점 사이의 y거리초과: %d\n", i, j, temp);
				continue;
			}
			ope3++;
			temp = dist(i, j);
			//printf("%d번째 점과 %d번째 점 사이의 거리 : %d\n", i, j, temp);
			if(temp < min)
			{
				min = temp;
			}
		}
	}*/
	for(int i=areaLeft; i<=areaRight; i++)
	{
		ope1++;
		sortPointY[i][0] = point[i][0];
		sortPointY[i][1] = point[i][1];
	}
	//printf("check9 현재 start, end, mid, areaLeft, areaRight : %d %d %d %d %d\n", start, end, mid, areaLeft, areaRight);
	mergeSortY(areaLeft, areaRight);
	//printf("check10 현재 start, end, mid : %d %d %d\n", start, end, mid);
	for(int i=areaLeft; i<=areaRight; i++)
	{
		//printf("y좌표 정렬 후 sortPointY[%d]의 값 : %d, %d\n",i,sortPointY[i][0],sortPointY[i][1]);
	}
	for(int i=areaLeft; i<areaRight; i++)
	{
		for(int j=i+1; j<=areaRight; j++)
		{
			ope1++;
			//printf("check1 현재 i, j좌표 : %d %d /  areaLeft : %d / areaRight : %d\n",i,j,areaLeft, areaRight);
			temp = sortPointY[j][1] - sortPointY[i][1];
			if(temp<0)	temp*=-1;
			//printf("check2 현재 i, j좌표 : %d %d\n",i,j);
			if(temp > minRoot)
			{
				break;
			}
			//printf("check3 현재 i, j좌표 : %d %d\n",i,j);
			temp = (sortPointY[j][0] - sortPointY[i][0]) * (sortPointY[j][0] - sortPointY[i][0]) +  (sortPointY[j][1] - sortPointY[i][1]) * (sortPointY[j][1] - sortPointY[i][1]);
			//printf("check4 현재 i, j좌표 : %d %d\n",i,j);
			//printf("%d번째 점과 %d번째 점 사이의 거리 : %d / 좌표값 : %d %d, %d %d\n", i, j, temp, sortPointY[i][0], sortPointY[i][1], sortPointY[j][0], sortPointY[j][1]);
			if(temp < min)
			{
				min = temp;
			}
			if(min == 0)	
			{
				printf("0");
				exit(0);
			}
		}
	}
	//printf("check4 현재 start, end, mid : %d %d %d\n", start, end, mid);
	return min;
}

int dist(int index1, int index2)
{
	return (point[index2][0] - point[index1][0]) * (point[index2][0] - point[index1][0]) + (point[index2][1] - point[index1][1]) * (point[index2][1] - point[index1][1]);
}

int main(void)
{	
	int n=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&point[i][0], &point[i][1]);
		/*for(int j=0; j<i; j++)
		{
			ope1++;
			ope2++;
			if(point[i][0] == point[j][0] && point[i][1] == point[j][1])
			{
			printf("%d %d 같은좌표\n",point[i][0], point[i][1]);
			printf("0\n");
			return 0;
			}
		}*/
	}
	mergeSort(0, n-1);
	for(int i=0; i<n; i++)
	{
		//printf("정렬 후 %d번째 x, y 값 : %d, %d\n",i,point[i][0], point[i][1]);
	}
	printf("%d\n",calMinDist(0, n-1, (n-1)/2));
	//printf("연산 횟수 : 1-%d 2-%d 3-%d ",ope1, ope2, ope3);
	
	return 0;
}
