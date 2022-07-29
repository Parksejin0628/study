#pragma once
#include"Common.h"

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum);
	Gun(Gun* ref);
	void Shot();
};
