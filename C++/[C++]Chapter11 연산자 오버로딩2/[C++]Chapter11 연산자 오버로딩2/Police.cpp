#include"Police.h"

Police::Police(int bnum, int bcuff) : handcuffs(bcuff)
{
	if (bnum > 0)
	{
		pistol = new Gun(bnum);
	}
	else
	{
		pistol = NULL;
	}
}

Police::Police(const Police& ref) : handcuffs(ref.handcuffs)
{
	if (ref.pistol != NULL)
	{
		pistol = new Gun(ref.pistol);
	}
	else
	{
		pistol = NULL;
	}
}

void Police::PutHandcuff()
{
	cout << "SNAP!" << endl;
	handcuffs--;
}

void Police::Shot()
{
	if (pistol == NULL)
	{
		cout << "Hut BBANG!" << endl;
	}
	else
	{
		pistol->Shot();
	}
}

Police& Police::operator=(const Police& ref)
{
	delete pistol;
	handcuffs = ref.handcuffs;
	pistol = new Gun(ref.pistol);

	return *this;
}

void Police::ShowPolice()
{
	cout << "¼ö°©°¹¼ö : " << handcuffs << endl;
	cout << "ÃÑ ÁÖ¼Ò : " << pistol << endl;
}

Police::~Police()
{
	if (pistol != NULL)
	{
		delete pistol;
	}
}