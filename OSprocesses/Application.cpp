#include "stdafx.h"



Application::Application(string name, DynamicLibrary **libs)
{
	_libraries = libs;
	_size = 50 + rand()%100;
	_name = name;
	counter = _procCounter = 2 + (rand() % 3);
	_processesCreation = firstProcess = _processesCounter = 
		(Process*)operator new(sizeof(Process) * counter);
	for (int i = 0; i < counter; ++i)
		new(&_processesCreation[i]) Process(this, 2);
	libCounter = 0;
	
}

Application::~Application()
{
	for (int i = 0; i < _procCounter; ++i)
		_processesCreation[i].~Process();

	operator delete(firstProcess);
	
}

string Application::getName()
{
	return _name;
}

bool Application::running(int quants)
{
	while (true)
	{
		if (quants--)
		{
			cout << "process #" << _procCounter - counter << "is running" << "\n";
			if (_processesCounter->running())
			{
				_processesCounter++; counter--;
				if (!counter)
				{
					return true;
				}
			}

		}
		else
			return false;
	}
}

int Application::getSize()
{
	int retSize = _size;
	for (int i = 0; i < libCounter; i++)
	{
		DynamicLibrary* dl = _libs.front();
		_libs.pop();
		retSize += dl->getSize();
		_libs.push(dl);
	}
	Process* pr = firstProcess;
	for (int i = 0; i < _procCounter; ++i)
	{
		retSize += pr->getSize();
		retSize++;
	}
	return retSize;
}

string Application::getLibs()
{
	string retString;
	for (int i = 0; i < libCounter; i++)
	{
		DynamicLibrary* dl = _libs.front();
		_libs.pop();
		retString += " " + dl->getName();
		_libs.push(dl);
	}
	return retString;
}

bool Application::addLib(int id)
{
	
	bool a = false;
	for (int i = 0; i < libCounter; i++)
	{
		DynamicLibrary* dl = _libs.front();
		_libs.pop();
		if (_libraries[id] == dl) a = true;
		_libs.push(dl);
	}
	if (!a)
	{
		_libs.push(_libraries[id]);
		libCounter++;
		return true;
	}
	return false;
}



/*count = 2 + (rand() % 3);	
	threads = (Thread*)operator new(sizeof(Thread) * count);
	for (int i = 0; i<count; ++i)
	new(&threads[i]) Thread(i, /*dynamic_cast<void*(int)> (activateThread));
	count = 0; */