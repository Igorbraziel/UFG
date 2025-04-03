#include <stdio.h>

#include <math.h>



#define getsig(i)        ((i)>>31 & 1)

#define getexp(i)        ((i)>>23 & 0xff)

#define getfrac(i)       ((i) & 0x7fffff)

#define makefloat(s,e,f) ( (((s) & 1) << 31) | (((e) & 0xff) << 23) | ((f) & 0x7fffff) )

typedef union {

  float f;

  unsigned int i;

} U;



float float2(float value){
    U u;
    u.f = value;
    unsigned int signal = getsig(u.i);
    unsigned int exponent = getexp(u.i);
    unsigned int fraction = getfrac(u.i);

    exponent++; // double the value

    u.i = makefloat(signal, exponent, fraction);
    return u.f;
}

int main(){
    float f = -1.125;

    f = float2(f);

    printf("%f\n", f);

    f = float2(f);

    printf("%f\n", f);

    f = float2(f);

    printf("%f\n", f);    
}