#pragma once

double sin(double x); //sinus of x
double cos(double x); //cosinus of x
double tan(double x); //tangens of x
double asin(double x); //arcsinus of x
double acos(double x); //arccosinus of x
double atan(double x); //arctangens of x
double atan2(double y, double x); //arctangens of y/x
double sinh(double x); //sinus hyperbolicus of x
double cosh(double x); //cosinus hyperbolicus of x
double tanh(double x); //tangens hyperbolicus of x
double exp(double x); //e^x
double frexp(double x, int* exp); // The returned value is the mantissa and the integer pointed to by exponent is the exponent. The resultant value is x = mantissa * 2 ^ exponent.
double log(double x); //logarithm of x
double log10(double x); //logarithm of x with base 10
double sqrt(double x); //square root of x
double pow(double x, double y); //x to the power of y
double ceil(double x); //round up x to the nearest integer
double floor(double x); //round down x to the nearest integer
double fabs(double x); //absolute value of x
double ldexp(double x, int n); //x * 2^n
double modf(double x, double* iptr); //split x into fraction and integer
double fmod(double x, double y); //fractional part of x/y

//C99 functions

double acosh(double x);
double asinh(double x);
double atanh(double x);
double exp2(double x);
double expm1(double x);
int ilogb(double x);
double log1p(double x);
double log2(double x);
double logb(double x);
double scalbn(double x, int n);
double scalbln(double x, long int n);
double cbrt(double x);
double hypot(double x, double y);
double erf(double x);
double erfc(double x);
double tgamma(double x);
double lgamma(double x);
double trunc(double x);
double round(double x);
long int lround(double x);
long long int llround(double x);
double rint(double x);
long int lrint(double x);
long long int llrint(double x);
double nearbyint(double x);
double remainder(double numer, double denom);
double remquo(double numer, double denom, int* quot);
double copysign(double x, double y);
double nan(const char* tagp);
double nextafter(double x, double y);
double nexttoward(double x, long double y);
double fmax(double x, double y);
double fmin(double x, double y);
double fdim(double x, double y);
double fma(double x, double y, double z);