#pragma once
#include"Common.h"
#include"Arr.h"

class BoundCheck2DIntArray
{
private:
	Array* array2D;
	int arr2DLen;
public:
	BoundCheck2DIntArray(int row, int column);
	~BoundCheck2DIntArray();
	Array& operator[](int idx);
};
