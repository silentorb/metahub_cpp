// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MetaHub.h"
#include <iostream>
#include <fstream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream t("test.txt");
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	MetaHub::parse(str);
	std::cin.get();
	return 0;
}

