#pragma once

#include "stdafx.h"
class Thread;


class Process : public Element
{
	Application* _parent;
private:
	int _type;
	queue <Thread*> threads;
	int threadCount;

public:
	Process(Application* , int type = 1);
	~Process();
	bool running();
	void activateThread(int id);
	Application* getParent();
};