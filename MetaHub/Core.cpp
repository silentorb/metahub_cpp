#include "StdAfx.h"
#include "Core.h"
#include <algorithm>

Core::Core(void)
{
}

Core::~Core(void)
{
	std::for_each(classes.begin(), classes.end(), delete_pointed_to<Meta_Class>);
}
