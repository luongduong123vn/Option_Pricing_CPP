//Purpose: The source file of EuropeanOption
//Date: 11/11/23

#include "PerpetualAmericanOption.h"
#include "Option_func.h"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace boost::math;
using namespace std;

double PerpetualAmericanOption::CallPrice() const
{ // Price of call

	return PerpetualCall(K, sig, r, U, b);
}

double PerpetualAmericanOption::PutPrice() const
{ // Price of put

	return PerpetualPut(K, sig, r, U, b);
}

void PerpetualAmericanOption::Init()
{ // Initialise all default values

	Option::Init();
	K = 100;
	sig = 0.1;
	r = 0.1;
	U = 110;
	b = r;
}

void PerpetualAmericanOption::Copy(const PerpetualAmericanOption& source)
{ // Copy all values

	Option::Copy(source);
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;
}

PerpetualAmericanOption::PerpetualAmericanOption() : Option()
{ // Default constructor

	Init();
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : Option(source)
{ // Copy constructor

	Copy(source);
}

PerpetualAmericanOption::PerpetualAmericanOption(const enum OptionType& optionType) : Option(optionType)
{ // Constructor with option type

	Init();
}

PerpetualAmericanOption::PerpetualAmericanOption(const struct PerpetualAmericanOptionData& optionData) : Option()
{ // Constructor with option data

	Init();
	K = optionData.K;
	sig = optionData.sig;
	r = optionData.r;
	U = optionData.U;
	b = optionData.b;
}

PerpetualAmericanOption::~PerpetualAmericanOption()
{ // Destructor
}

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source)
{ // Assignment operator

	Option::operator = (source);

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

double PerpetualAmericanOption::PriceWithS(double newU) const
{ // Using underlying price as argument

	if (optionType == Call)
	{
		return PerpetualCall(K, sig, r, newU, b);
	}
	else
	{
		return PerpetualPut(K, sig, r, newU, b);
	}
}



