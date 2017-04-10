#include "stdafx.h"


Process::Process(Application* parent, int type)
{
	_size = rand() % 30;
	_parent = parent;
	threadCount = 0;
	switch (type)
	{
	case 1:
		threads.push(new Thread(this, ++threadCount));
		break;
	case 2:
		threads.push(new Thread(this, ++threadCount));
		threads.push(new Thread(this, ++threadCount));
		
		break;
	default:
		break;
	}
}

Process::~Process()
{
	
}

bool Process::running()
{
	
	if (!threads.empty())
	{
		Thread* thrd = threads.front();
		threads.pop();
		cout << "Running thread # \"" << thrd->getId() << "\"\n";
		if (thrd->running()) 
		{
			
		}
		else
		{
			threads.push(thrd);
		}
	}
	else
		return true;
	return false;
}

void Process::activateThread(int id)
{
}

Application* Process::getParent()
{
	return _parent;
}

