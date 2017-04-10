#pragma once
using namespace std;

#include "stdafx.h"
class Process;
class DynamicLibrary;

#include "Element.h"

class Application : public Element
{
	Process* firstProcess;
	Process* _processesCreation;
	Process* _processesCounter;
	queue<DynamicLibrary*> _libs;
	int _procCounter;
	int counter;
	void* _activateThread;
	int libCounter;
	DynamicLibrary **_libraries;
//private:
	
	
public:
	Application(string name, DynamicLibrary**libs);
	~Application();
	string getName();
	bool running(int quants);
	int getSize();
	string getLibs();
	bool addLib(int id);
};