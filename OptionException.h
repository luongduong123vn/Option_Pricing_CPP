//Purpose: The head file of OptionException
//Date: 11/11/23

#ifndef OptionException_h
#define OptionException_h

#include <iostream>
using namespace std;

class OptionException
{
public:
	// Constructor and destructor
	OptionException()
	{					// Default constructor
	}

	virtual ~OptionException()
	{					// Destructor
	}

	virtual string GetMessage() = 0;
};

#endif