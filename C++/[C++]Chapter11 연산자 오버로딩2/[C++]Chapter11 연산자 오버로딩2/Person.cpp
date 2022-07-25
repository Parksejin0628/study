#include"Person.h"

Person::Person(const char *myname, int myage)
{
	int len = strlen(myname) + 1;
	name = new char[len];
	strcpy(name, myname);
	age = myage;
}
void Person::ShowPersonInfo() const
{
	cout << "이름: " << name << endl;
	cout << "나이: " << age << endl;
}
Person::~Person()
{
	delete[]name;
	cout << "called destructor!" << endl;
}

Person& Person::operator=(const Person& ref)
{
	delete[]name;
	int len = strlen(ref.name) + 1;
	name = new char[len];
	strcpy(name, ref.name);
	age = ref.age;

	return *this;
}