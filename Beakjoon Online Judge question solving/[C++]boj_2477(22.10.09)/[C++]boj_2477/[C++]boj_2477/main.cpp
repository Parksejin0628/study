#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

class Area
{
private:
	int* length;
	int koreanMelon;
public:
	Area() : koreanMelon(0)
	{
		length = new int[6];
	}
	~Area()
	{
		delete[]length;
	}
	void input()
	{
		int temp = 0;
		scanf("%d", &koreanMelon);
		for (int i = 0; i < 6; i++)
		{
			scanf("%d %d", &temp, &length[i]);
		}
	}
	int calArea()
	{
		int height_long = 0;
		int width_long = 0;
		int height_out = 0;
		int width_out = 0;
		int tempIndex = 0;
		int area = 0;
		for (int i = 0; i < 6; i += 2)
		{
			if (length[i] > height_long)
			{
				tempIndex = i;
				height_long = length[i];
			}
		}
		height_out = length[(tempIndex + 3) % 6];
		for (int i = 1; i < 6; i += 2)
		{
			if (length[i] > width_long)
			{
				tempIndex = i;
				width_long = length[i];
			}
		}
		width_out = length[(tempIndex + 3) % 6];
		//cout << height_long << " " << width_long << " " << height_out << " " << width_out << endl;
		//cout << height_long * width_long << " " << height_out * width_out << endl;
		area = height_long * width_long - height_out * width_out;
		return area * koreanMelon;
	}
};

int main(void)
{
	Area area;
	area.input();
	printf("%d", area.calArea());

	return 0;
}