#pragma once
#include <string>
#include <vector>
#include <map>
#include "Meta_Class.h"

using namespace std;
typedef unsigned short ushort;

template <typename T>
void delete_pointed_to(T* const ptr)
{
	delete ptr;
}

class Core
{
public:
	Core(void);
	~Core(void);

	vector<Meta_Class*> classes;
	map <string, int> class_names;
};

