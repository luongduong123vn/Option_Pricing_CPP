#include "Option_func.h"
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>

using namespace boost::math;
using namespace std;

vector<double> GenerateMeshArray(double begin, double end, int n)
{
	vector<double> vec;
	// NB Full array (includes end points)
	double h = (end - begin) / (n - 1);
	//for loop to iterate to add valve to vector
	for (int i = 0; i < n; i++)
	{
		vec.push_back(begin + h * i);
	}

	return vec;
}

double call_price(double T, double K, double sig, double r, double U, double b)
{
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);

	return (U * exp((b - r) * T) * cdf(normalDist, d1)) - (K * exp(-r * T) * cdf(normalDist, d2));
}

double put_price(double T, double K, double sig, double r, double U, double b)
{
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);

	return (K * exp(-r * T) * cdf(normalDist, -d2)) - (U * exp((b - r) * T) * cdf(normalDist, -d1));
}

double call_delta(double T, double K, double sig, double r, double U, double b)
{//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return exp((b - r) * T) * cdf(normalDist, d1);
}

double put_delta(double T, double K, double sig, double r, double U, double b)
{
	return call_delta(T, K, sig, r, U, b) - exp((b - r) * T);
}

double call_gamma(double T, double K, double sig, double r, double U, double b)
{//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return pdf(normalDist, d1) * exp((b - r) * T) / (U * sig * sqrt(T));
}

double put_gamma(double T, double K, double sig, double r, double U, double b)
{
	return call_gamma(T, K, sig, r, U, b);
}


double call_vega(double T, double K, double sig, double r, double U, double b)
{//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	return U * sqrt(T) * exp((b - r) * T) * pdf(normalDist, d1);
}

double put_vega(double T, double K, double sig, double r, double U, double b)
{
	return call_vega(T, K, sig, r, U, b);
}

double call_theta(double T, double K, double sig, double r, double U, double b)
{//using boost library's normal distribution 
	normal_distribution<> normalDist(0, 1);
	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;
	return -U * sig * exp((b - r) * T) * pdf(normalDist, d1) / (2 * sqrt(T))
		- (b - r) * U * exp((b - r) * T) * cdf(normalDist, d1) - r * K * exp(-r * T) * cdf(normalDist, d2);
}

double put_theta(double T, double K, double sig, double r, double U, double b)
{
	return call_theta(T, K, sig, r, U, b) + r * K * exp(-r * T) + U * exp((b - r) * T) * (b - r);
}