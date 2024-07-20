#include <vector> 
using namespace std;

#ifndef OPTIONEXTRAS_HPP 
#define OPTIONEXTRAS_HPP

// Global Functions

vector<double> GenerateMeshArray(double begin, double end, int n);
double call_price(double T, double K, double sig, double r, double U, double b);

double put_price(double T, double K, double sig, double r, double U, double b);

double call_delta(double T, double K, double sig, double r, double U, double b);

double put_delta(double T, double K, double sig, double r, double U, double b);

double call_gamma(double T, double K, double sig, double r, double U, double b);

double put_gamma(double T, double K, double sig, double r, double U, double b);

double call_vega(double T, double K, double sig, double r, double U, double b);

double put_vega(double T, double K, double sig, double r, double U, double b);

double call_theta(double T, double K, double sig, double r, double U, double b);

double put_theta(double T, double K, double sig, double r, double U, double b);
#endif 
