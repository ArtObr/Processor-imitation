#include "stdafx.h"


Thread::Thread(Process* parent, int id)
{
	_parent = parent;
	_id = id;
	quantsToComplete = 1 + (rand() % 3);
}

Thread::~Thread()
{

}

bool Thread::running()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	cout << "-quant\n";
	if (rand() % 10 < 5)
		if (_parent->getParent()->addLib(2))
			cout << "Add lib # 1";
	if (--quantsToComplete == 0) return true;
	return false;
}

int Thread::getId()
{
	return _id;
}


