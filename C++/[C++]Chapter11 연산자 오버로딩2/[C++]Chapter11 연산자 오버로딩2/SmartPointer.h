#pragma once
#include"Common.h"
#include"Person.h"

class SmartPointer
{
private:
	Person* sptr;
public:
	SmartPointer(Person* ptr) : sptr(ptr)
	{
		
	}
	Person& operator*() const
	{
		return *sptr;
	}
	Person* operator->() const
	{
		return sptr;
	}
	~SmartPointer()
	{
		delete sptr;
	}
};