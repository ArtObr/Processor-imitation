#pragma once
class DynamicLibrary
{
	string _name;
	int _size;
public:
	DynamicLibrary(string name, int size);
	~DynamicLibrary();
	int getSize();
	string getName();
private:

};