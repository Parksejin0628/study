#include"BoundCheck2DIntArray.h"

BoundCheck2DIntArray::BoundCheck2DIntArray(int row, int column) : arr2DLen(row)
{
	array2D = new Array[arr2DLen];
	for (int i = 0; i < arr2DLen; i++)
	{
		array2D[i].init(column);
	}
}

BoundCheck2DIntArray::~BoundCheck2DIntArray()
{
	delete[]array2D;
}

Array& BoundCheck2DIntArray::operator[](int idx)
{
	if (idx < 0 || idx >= arr2DLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return array2D[idx];
}
