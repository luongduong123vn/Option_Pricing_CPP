//Purpose: The source file of EuropeanOption
//Date: 11/11/23

#include "EuropeanOption.h"
#include "Option_func.h"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace boost::math;
using namespace std;

double EuropeanOption::CallPrice() const
{ // Price of call

	return call_price(T, K, sig, r, U, b);
}

double EuropeanOption::PutPrice() const
{ // Price of put

	return put_price(T, K, sig, r, U, b);
}

double EuropeanOption::CallDelta() const
{ // Delta of call

	return call_delta(T, K, sig, r, U, b);
}

double EuropeanOption::PutDelta() const
{ // Delta of put

	return put_delta(T, K, sig, r, U, b);
}

double EuropeanOption::CallGamma() const
{ // Gamma of call

	return call_gamma(T, K, sig, r, U, b);
}

double EuropeanOption::PutGamma() const
{ // Gamma of put

	return put_gamma(T, K, sig, r, U, b);
}

double EuropeanOption::CallVega() const
{ // Vega of call

	return call_vega(T, K, sig, r, U, b);
}

double EuropeanOption::PutVega() const
{ // Vega of put

	return put_vega(T, K, sig, r, U, b);
}

double EuropeanOption::CallTheta() const
{ // Theta of call

	return call_theta(T, K, sig, r, U, b);
}

double EuropeanOption::PutTheta() const
{ // Theta of put

	return put_theta(T, K, sig, r, U, b);
}

void EuropeanOption::Init()
{ // Initialise all default values

	Option::Init();
	T = 0.25;
	K = 65;
	sig = 0.30;
	r = 0.08;
	U = 60;
	b = r;
}

void EuropeanOption::Copy(const EuropeanOption& source)
{ // Copy all values

	Option::Copy(source);
	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;
}

EuropeanOption::EuropeanOption() : Option()
{ // Default constructor

	Init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& source) : Option(source)
{ // Copy constructor

	Copy(source);
}

EuropeanOption::EuropeanOption(const OptionType& newOptionType) : Option(newOptionType)
{ // Constructor with option type

	Init();
}

EuropeanOption::EuropeanOption(const struct EuropeanOptionData& optionData) : Option()
{ // Constructor with option data

	Init();
	T = optionData.T;
	K = optionData.K;
	sig = optionData.sig;
	r = optionData.r;
	U = optionData.U;
	b = optionData.b;
}

EuropeanOption::~EuropeanOption()
{ // Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)
{ // Assignment operator

	Option::operator = (source);

	if (this == &source)
	{
		return *this;
	}

	Copy(source);

	return *this;
}

double EuropeanOption::CallToPut(double c) const
{ // Use put-call parity to calculate put price

	return c + K * exp(-r * T) - U;
}

double EuropeanOption::PutToCall(double p) const
{ // Use put-call parity to calculate call price

	return p + U - K * exp(-r * T);
}

double EuropeanOption::PriceWithS(double newU) const
{
	if (optionType == Call)
	{
		return call_price(T, K, sig, r, newU, b);
	}
	else
	{
		return put_price(T, K, sig, r, newU, b);
	}
}

double EuropeanOption::PriceWithT(double newT) const
{
	if (optionType == Call)
	{
		return call_price(newT, K, sig, r, U, b);
	}
	else
	{
		return put_price(newT, K, sig, r, U, b);
	}
}

double EuropeanOption::PriceWithSig(double newSig) const
{
	if (optionType == Call)
	{
		return call_price(T, K, newSig, r, U, b);
	}
	else
	{
		return put_price(T, K, newSig, r, U, b);
	}
}

double EuropeanOption::DeltaDiff(double U, double h) const
{
	return (PriceWithS(U + h) - PriceWithS(U - h)) / (2.0 * h);
}

double EuropeanOption::GammaDiff(double U, double h) const
{
	return (PriceWithS(U + h) - 2.0 * PriceWithS(U) + PriceWithS(U - h)) / (h * h);
}


