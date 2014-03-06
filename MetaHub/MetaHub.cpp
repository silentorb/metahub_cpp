// MetaHub.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MetaHub.h"


// This is an example of an exported variable
METAHUB_API int nMetaHub=0;

// This is an example of an exported function.
METAHUB_API int fnMetaHub(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see MetaHub.h for the class definition
CMetaHub::CMetaHub()
{
	return;
}
