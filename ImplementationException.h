//Purpose: The head file of NoImplementationException
//Date: 11/11/23

#ifndef ImplementationException_h
#define ImplementationException_h

#include "OptionException.h"
#include <sstream>
#include <iostream>
using namespace std;

class ImplementationException : public OptionException
{
private:
	string m_functionName;

public:
	// Constructors and destructor
	ImplementationException() : OptionException()
	{ // Default constructor
	}

	ImplementationException(string functionName) : OptionException()
	{ // Constructor accepting erroneous function name

		m_functionName = functionName;
	}

	virtual ~ImplementationException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "No implementation of the " << m_functionName << " function in the class";

		return stream.str();
	}
};

#endif