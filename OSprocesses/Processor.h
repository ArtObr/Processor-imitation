#pragma once

#include "stdafx.h"

class Processor
{
private:
	queue<Application*> myqueue;
	
public:
	Processor(DynamicLibrary** libs);
	~Processor();
	void initApplication(Application* app);
	void startProc(bool step = false);

};