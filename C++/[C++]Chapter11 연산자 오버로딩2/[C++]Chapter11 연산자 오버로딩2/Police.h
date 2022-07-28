#pragma once
#include"common.h"
#include"Gun.h"

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff);
	Police(const Police& ref);
	~Police();
	void PutHandcuff();
	void Shot();
	void ShowPolice();
	Police& operator=(const Police& ref);
};