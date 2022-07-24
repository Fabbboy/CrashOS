#include "math.h"
#include "limits.h"

double sin(double x);
double cos(double x); //cosinus of x

double tan(double x);

double asin(double x); //arcsinus of x
double acos(double x); //arccosinus of x
double atan(double x); //arctangens of x
double atan2(double y, double x); //arctangens of y/x
double sinh(double x); //sinus hyperbolicus of x
double cosh(double x); //cosinus hyperbolicus of x
double tanh(double x); //tangens hyperbolicus of x

double exp(double x) {
    double sum = 1.0f;

    for(int i = 9; i > 0; --i) {
        sum = 1 + x * sum / i;
    }

    return sum;
}

double frexp(double x, int* exp);

double log(double x); //logarithm of x (ln)
double log10(double x); //logarithm of x with base 10 (log10)
double sqrt(double num);
double pow(double base, double exp);

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