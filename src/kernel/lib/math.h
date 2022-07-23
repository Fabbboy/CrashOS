

#ifndef CRASHOS_MATH_H
#define CRASHOS_MATH_H

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


#endif //CRASHOS_MATH_H
