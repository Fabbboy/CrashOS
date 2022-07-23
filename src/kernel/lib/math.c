#include "./math.h"
#include "./limits.h"

double sin(double x);
double cos(double x); //cosinus of x

double tan(double x){
    return sin(x) / cos(x);
}

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

double sqrt(double num){
    unsigned res = 0;
    unsigned bit = 1u << (sizeof(num) * CHAR_BIT - 2);

    // "bit" starts at the highest power of four <= the argument.
    while (bit > num)
        bit >>= 2;

    while (bit > 0) {
        if (num >= res + bit) {
            num -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

double pow(double x, double y){
    if (y == 1.0)
        return 0;
    if (y == 0.0)
        return 0;
    //calculate x to the power of y
    return (x*x) * y;
}

double ceil(double x){
    if (x == 0)
        return 0;
    if (x < 0)
        return (int)x - 1;
    return (int)x;
}

double floor(double x){
    if (x == 0)
        return 0;
    if (x < 0)
        return (int)x + 1;
    return (int)x;
}

double fabs(double x){
    if (x < 0)
        return x * -1;
    return x;
}

double ldexp(double x, int n){
    return x * pow(2, n);
}

double modf(double x, double* iptr){
    *iptr = (int)x;
    return x - *iptr;
}

double fmod(double x, double y){
    return x - (int)x / y * y;
}