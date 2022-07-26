#include "math.h"
#include "memory.h"

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
    double alpha = (x - 1) / (x + 1), ans = alpha;
    double save = ans * alpha * alpha;

    for(int i = 2; i <= 100; i++) {
        ans += (1.0/(2 * i - 1)) * save;
        save = save * alpha * alpha;
    }

    return 2.0 * ans;
}

double log10(double x) {
    return log(x) / LN10;
}

double sqrt(double num) {
    double z = 1.0;
    for(int i = 1; i <= 10; i++) {
        z -= (z*z - num) / (2*z);
    }

    return z;
}

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
    const int FP64_MIN_EXPO = -1022;
    const int FP64_MANT_BITS = 52;
    const int FP64_EXPO_BIAS = 1023;

    x = (x < FP64_MIN_EXPO) ? FP64_MIN_EXPO : x;
    double w = floor(x);
    double z = x - w;
    double approx = -0x1.6e75d58p+2 + 0x1.bba7414p+4 / (0x1.35eccbap+2 - z) - 0x1.f5e53c2p-2 * z;
    int64_t resi = ((1LL << FP64_MANT_BITS) * (w + FP64_EXPO_BIAS + approx));
    double res;
    memcpy(&res, &resi, sizeof res);
    return res;
}

double expm1(double x) {
    return exp(x) - 1;
}

int ilogb(double x);

double log1p(double x) {
    return log(1 + x);
}

double log2(double x) {
    return log(x) / LN2;
}

double logb(double x);
double scalbn(double x, int n);
double scalbln(double x, long int n);
double cbrt(double x);

double hypot(double x, double y) {
    return sqrt(x*x + y*y);
}

double erf(double x);
double erfc(double x);
double tgamma(double x);
double lgamma(double x);

double trunc(double x) {
    return x < 0 ? ceil(x) : floor(x);
}

double round(double x) {
    return signbit(x) ? ceil(x - 0.5) : floor(x - 0.5);
}

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