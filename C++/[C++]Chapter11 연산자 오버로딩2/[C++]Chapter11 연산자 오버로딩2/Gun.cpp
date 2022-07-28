#include"Gun.h"

Gun::Gun(int bnum) : bullet(bnum)
{

}

Gun::Gun(Gun* ref) : bullet(ref->bullet)
{

}

void Gun::Shot()
{
	cout << "BBANG!" << endl;
	bullet--;
}
