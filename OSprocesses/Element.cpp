#include "stdafx.h"

Element::~Element()
{
}

string Element::getName()
{
	return _name;
}

void Element::setName(string name)
{
	_name = name;
}

int Element::getSize()
{
	return _size;
}

void Element::setSize(int size)
{
	_size = size;
}
