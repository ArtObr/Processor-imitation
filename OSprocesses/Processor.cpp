#include "stdafx.h"



Processor::Processor(DynamicLibrary** libs)
{
	initApplication(new Application("System Application #1", libs));
	//initApplication(new Application("System Application #2"));
	//initApplication(new Application("Game"));
}

Processor::~Processor()
{
	while (!myqueue.empty())
	{
		Application* app = myqueue.front();
		myqueue.pop();
		delete app;
	}
}

void Processor::initApplication(Application * app)
{
	myqueue.push(app);
}

void Processor::startProc(bool step)
{
	int c = 'a';
	while (true)
	{
		if (!myqueue.empty())
		{
			
			Application* app = myqueue.front();
			myqueue.pop();
			cout << "Running app: \"" << app->getName() << "\"\n";
			if (app->running(5))
			{
				cout << "App \""
					<< app->getName() << "\" successfully executed with "
					<< app->getSize() << " bytes used. Used libs:"
					<< app->getLibs() << "\n";
				delete app;
			}
			else
			{
				cout << "App \"" << app->getName() << "\" is waiting" << "\n";
				myqueue.push(app);
			}
		}
		else
		{
			//cout << "Processor awaits \n";
			std::this_thread::sleep_for(std::chrono::seconds(5));
		}
	}
}
