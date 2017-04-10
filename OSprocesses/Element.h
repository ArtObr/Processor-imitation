#pragma once

#include "stdafx.h"

class Element
{
protected:
	string _name;
	int _size;

public:
	Element()
	{
	}
	~Element();
	string getName();
	void setName(string name);
	int getSize();
	void setSize(int size);


private:

};

