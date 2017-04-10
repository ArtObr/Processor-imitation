#include "stdafx.h"


DynamicLibrary::DynamicLibrary(string name, int size)
{
	_name = name;
	_size = size;
}

DynamicLibrary::~DynamicLibrary()
{
}

int DynamicLibrary::getSize()
{
	return _size;
}

string DynamicLibrary::getName()
{
	return _name;
}
