#include <stdio.h>

#include <math.h>

#include <limits.h>



#define getsig(x)        ((x)>>31 & 1)

#define getexp(x)        ((x)>>23 & 0xff)

#define getfrac(x)       ((x) & 0x7fffff)

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))



typedef union {

  float f;

  unsigned int i;

} U; 



int float2int(float value){
    U u;
    u.f = value;

    unsigned int s = getsig(u.i);
    unsigned int M = getfrac(u.i);
    unsigned int exp = getexp(u.i);
    if(exp == 0){
        return 0;
    }

    // if((exp >> 23) == 0xFF){
    //     if(M == 0){
    //         return INFINITY;
    //     } else {
    //         return NAN;
    //     }
    // }

    int E = exp - 127;

    if(E < 0) return 0;

    u.i = makefloat(0, 1, M);

    int r;

    if(E > 23){
        r = u.i << (E - 23);
    } else {
        r = u.i >> (23 - E);
    }
    
    if(s){
        r = -r;
    }

    return r;
}





int main() {

   float f;



   printf("\n******** float2int ****************\n");



   f = 12.25;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));

   f = -0.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 0.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -0.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 0.125;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -0.125;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 1.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -1.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 1.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -1.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 2.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -2.5;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 5.4;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -5.4;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 12345.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -12345.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 14690064.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -14690064.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = 167788544.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = -167788544.0;

   printf(" %+10.4f -> %d %d\n", f, (int)f, float2int(f));



   f = (float) pow(2,31);

   printf(" %+10.4f (2^31) = overflow -> %d %d\n", f, (int)f, float2int(f));



   f = -f;

   printf(" %+10.4f (-2^31) -> %d %d\n", f, (int)f, float2int(f));



   f = -((float) pow(2,32));

   printf(" %+10.4f (-2^32 = overflow) -> %d %d\n", f, (int)f, float2int(f));



   return 0;

}