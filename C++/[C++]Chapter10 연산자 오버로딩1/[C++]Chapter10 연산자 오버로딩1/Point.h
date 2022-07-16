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
	Point operator+=(const Point &ref) const;
	Point operator-=(const Point &ref) const;
	Point& operator++();
	const Point& operator++(int);
	Point& operator-() const;
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
	friend Point& operator~(const Point &pos);
	friend Point& operator+(int num, const Point &pos);
	void printPos();
};