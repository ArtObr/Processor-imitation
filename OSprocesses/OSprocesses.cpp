// OSprocesses.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;

void mainMenu()
{
	string command;
	while (true) 
	{ 
		cout << (rand() % 10);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
	}
}

void write()
{
	
}

int main()
{
	DynamicLibrary** libs;
	int libCount = 4;
	libs = new DynamicLibrary*[libCount];
	int i = 0;
	libs[i++] = new DynamicLibrary("iostream", 67);
	libs[i++] = new DynamicLibrary("generics", 30);
	libs[i++] = new DynamicLibrary("collections", 26);
	libs[i++] = new DynamicLibrary("simpleGraphic", 83);

	Processor* proc = new Processor(libs);
	proc->startProc();
	for (int i = 0; i < libCount; i++)
		delete &libs[i];
	delete libs;
	/*thread thr1 = thread(mainMenu);
	thread thr2 = thread(write);*/
	//thr1.join();
	return 0;
}




/*

class Person
{
protected:
	string _name;
	string _surname;
	string _lastname;
public:

	virtual string getName() = 0;

	void setName(string s) { _name = s; }
	void setSurname(string s) { _surname = s; }
	void setLastname(string s) { _lastname = s; }
};

class Student : public Person
{
public:
	string getFullName()
	{
		return _surname + " " + _name + " " + _lastname;
	}
};

class Position
{
	string _name;
public:
	const string& name()
	{
		return _name;
	}

	Position(string n)
	{
		_name = n;
	}
};

class Employee : public Person
{
	Position** _pos;
public:
	Employee()
	{
		_pos = new Position*[10]{0};
	}
	~Employee()
	{
		delete[] _pos;
	}
	string getFullName()
	{
		string pos = "";
		Position *p = _pos[0];
		while (p)
		{
			pos += p->name + " ";
			p++;
		}
		pos += _surname + " " + _name[0] + " " + _lastname[0];
		return pos;
	}
	};*/