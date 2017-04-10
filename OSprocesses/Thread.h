#pragma once
#include "stdafx.h"



class Thread : public Element
{
	Process* _parent;
	int _id;
	int quantsToComplete;
public:
	Thread(Process* parent, int id);
	~Thread();
	bool running();
	int getId();
private:

};