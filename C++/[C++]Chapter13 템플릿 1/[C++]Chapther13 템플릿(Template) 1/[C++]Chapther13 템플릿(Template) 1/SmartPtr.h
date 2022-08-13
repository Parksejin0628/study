#pragma once

#include"Common.h"

template<typename T>
class SmartPtr
{
private:
	T* objptr;
public:
	SmartPtr(T* ptr) : objptr(ptr) { }
	T& operator*() const { return *objptr; }
	T* operator->() const { return objptr; }
	~SmartPtr() { delete objptr; }
};