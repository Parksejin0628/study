#include"Point.h"

Point::Point(int xpos, int ypos) : xpos(xpos), ypos(ypos)
{

}

Point Point::operator+=(const Point &ref)
{
	Point pos(xpos + ref.xpos, ypos + ref.ypos);
	return pos;
}

Point Point::operator-=(const Point &ref)
{
	Point pos(xpos - ref.xpos, ypos - ref.ypos);
	return pos;
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

void Point::printPos()
{
	cout << "(" << xpos << ", " << ypos << ")" << endl;

	return;
}
