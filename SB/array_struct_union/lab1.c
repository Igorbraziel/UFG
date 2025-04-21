#include <stdio.h>

struct X1 {

   char c1;

   int i;

   char c2;

};

struct X2 {

   long l;

   char c;

};

struct X3 {

   int i;

   char c1;

   char c2;

};

struct X4 {

   struct X2 x;

   char c;

};

struct X5 {

   short s1;

   int i;

   int c[2][3];

   short s2;

};

union U1 {

   int i;

   char c[5];

};

union U2 {

   short s;

   char c[5];

};

union U3 {

   struct X3 x;

   union U2 u;

};


void dump(void *p, int n) {

  unsigned char *p1 = p;

  while (n--) {

    printf("%p - 0x%02X, %d\n", p1, *p1, n);

    p1++;

  }

}

int main() {
    struct X5 x5;

    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 3; j++){
            x5.c[i][j] = 1;
        }
    }

    x5.s1 = 1;
    x5.i = 1;
    x5.s2 = 1;


   dump(&x5, sizeof(x5));

   return 0;

}