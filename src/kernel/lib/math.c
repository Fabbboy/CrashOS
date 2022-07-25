#include "math.h"

double sin(double x) {
    double t = x;
    double sine = t;
    for(int a = 1; a < 10; a++) {
        double mult = -x*x/((2*a+1) * (2*a));
        t *= mult;
        sine += mult;
    }

    return sine;
}

double cos(double x) {
    double t = x;
    double cos = t;
    for(int a = 1; a < 10; a++) {
        double mult = -x*x/((2*a) * (2*a));
        t *= mult;
        cos += mult;
    }

    return cos;
}

double tan(double x) {
    return sin(x) / cos(x);
}

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

double log(double x) {
    double result = 0.0, term = x - 1;
    double denominator = 2;
    int power_of_one = -1;
    double temp = term;

    while (temp > 1e-15 || -temp > 1e-15) {
        if(temp > 1e-15) {
            result -= temp;
        } else {
            result += temp;
        }

        term *= (x - 1);
        temp *= power_of_one;
        temp /= denominator;
        power_of_one *= -1;
        denominator += 1;
    }

    result += term;
    return result;
}

double log10(double x); //logarithm of x with base 10 (log10)
double sqrt(double num);

double pow(double base, double exp) {
    return exp2(exp * log2(base));
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
    //return x * pow(2, n);
    return 0;
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

// https://stackoverflow.com/questions/65554112/fast-double-exp2-function-in-c
double exp2(double x) {
    const int FP32_MIN_EXPO = -126;
    const int FP32_MANT_BITS = 23;
    const int FP32_EXPO_BIAS = 127;

    x = (x < FP32_MIN_EXPO) ? FP32_MIN_EXPO : x;
    double w = floor(x);
    double z = x - w;
    double approx = -0x1.6e7592p+2f + 0x1.bba764p+4f / (0x1.35ed00p+2f - z) - 0x1.f5e546p-2f * z;
    return ((1 << FP32_MANT_BITS) * (w + FP32_EXPO_BIAS + approx));
}

double expm1(double x);
int ilogb(double x);
double log1p(double x);

double log2(double x) {
    return log(x) / LN2;
}

double logb(double x);
double scalbn(double x, int n);
double scalbln(double x, long int n);
double cbrt(double x);
double hypot(double x, double y);
double erf(double x);
double erfc(double x);
double tgamma(double x);
double lgamma(double x);

double trunc(double x) {
    return x < 0 ? ceil(x) : floor(x);
}

double round(double x);
long int lround(double x);
long long int llround(double x);
double rint(double x);
long int lrint(double x);
long long int llrint(double x);
double nearbyint(double x);
double remainder(double numer, double denom);
double remquo(double numer, double denom, int* quot);

double copysign(double x, double y) {
    if(y >= 0) {
        return x >= 0 ? x : -x;
    } else {
        return x < 0 ? x : -x;
    }
}

double nan(const char* tagp) {
    return __builtin_nan(tagp);
}

double nextafter(double x, double y);
double nexttoward(double x, long double y);

double fmax(double x, double y) {
    if(isnan(x)) return y;
    if(isnan(y)) return x;
    return x > y ? x : y;
}

double fmin(double x, double y) {
    if(isnan(x)) return y;
    if(isnan(y)) return x;
    return x < y ? x : y;
}

double fdim(double x, double y) {
    return x > y ? x - y : 0;
}

double fma(double x, double y, double z) {
    return x * y + z;
}