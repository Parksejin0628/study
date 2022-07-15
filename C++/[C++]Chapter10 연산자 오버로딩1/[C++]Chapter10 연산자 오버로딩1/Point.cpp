#include"Point.h"

Point::Point(int xpos, int ypos) : xpos(xpos), ypos(ypos)
{

}

Point Point::operator+=(const Point &ref) const
{
	Point pos(xpos + ref.xpos, ypos + ref.ypos);
	return pos;
}

Point Point::operator-=(const Point &ref) const
{
	Point pos(xpos - ref.xpos, ypos - ref.ypos);
	return pos;
}

Point& Point::operator++()
{
	xpos = xpos + 1;
	ypos = ypos + 1;

	return *this;
}

Point& Point::operator-() const
{
	Point returnObj(-xpos, -ypos);

	return returnObj;
}

Point operator-(const Point &pos1, const Point &pos2) 
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) 
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
	{
		return true;
	}
	return false;
}

bool operator!=(const Point &pos1, const Point &pos2) 
{
	bool result_eq = pos1 == pos2;
	return !result_eq;
}

Point& operator~(const Point &pos) 
{
	Point returnObj(pos.ypos, pos.xpos);
	return returnObj;
}

void Point::printPos()
{
	cout << "(" << xpos << ", " << ypos << ")" << endl;

	return;
}
