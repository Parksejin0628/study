#include"String.h"

String::String() : len(0)
{
	str = NULL;
}

String::String(const char* istr) : len(strlen(istr))
{
	str = new char[len + 1];
	strcpy(str, istr);
}

String::String(const String& cpy) : len(cpy.len)
{
	str = new char[len + 1];
	strcpy(str, cpy.str);
}

String::~String()
{
	if (str != NULL)
	{
		delete[]str;
	}
}

String& String::operator=(const String& cpy)
{
	if (str != NULL)
	{
		delete[]str;
	}

	len = cpy.len;
	str = new char[len + 1];
	strcpy(str, cpy.str);

	return *this;
}

String String::operator+(const String& other) const
{
	char* temp = new char[len + other.len + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	String ret(temp);
	delete[]temp;

	return ret;
}

String& String::operator+=(const String& other)
{
	len += other.len;
	char* temp = new char[len + 1];
	strcpy(temp, str);
	strcat(temp, other.str);
	if (str != NULL)
	{
		delete[]str;
	}
	str = temp;

	return *this;
}

bool String::operator==(const String& other) const
{
	if (!strcmp(str, other.str))
	{
		return true;
	}
	return false;
}

istream& operator>>(istream& ist, String& s)
{
	char* temp = new char[100];
	ist >> temp;
	s = String(temp);

	return ist;
}

ostream& operator<<(ostream& ost, const String& s)
{
	ost << s.str;
	return ost;
}