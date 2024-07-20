//Purpose: The head file of PerpetualAmericanOption
//Date: 11/11/23

#ifndef PerpetualAmericanOption_h
#define PerpetualAmericanOption_h

#include "Option.h"
#include <string>
#include <vector>
using namespace std;

class PerpetualAmericanOption : public Option
{
private:
	double CallPrice() const; // Price of call
	double PutPrice() const; // Price of put
	void Init(); // Initialise all default values
	void Copy(const PerpetualAmericanOption& source); // Copy all values

public:
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry

public:
	PerpetualAmericanOption(); // Default constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source); // Copy constructor
	PerpetualAmericanOption(const enum OptionType& optionType); // Constructor with option type
	PerpetualAmericanOption(const struct PerpetualAmericanOptionData& optionData); // Constructor with option data
	virtual ~PerpetualAmericanOption(); // Destructor

	// Member operator overloading
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	// Functions that calculate option price and sensitivities
	double PriceWithS(double newU) const; // Using underlying price as argument
};

struct PerpetualAmericanOptionData
{
	double K; // Strike price
	double sig; // volatility
	double r; // Risk free interest rate
	double U; // Current price of the underlying asset
	double b; // Cost of carry
};

#endif