#pragma once
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int xpos, int ypos);
	Point operator+=(const Point &ref);
	Point operator-=(const Point &ref);
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
	void printPos();
};