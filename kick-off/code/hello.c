#include <stdio.h>
#include <math.h>

struct complex{
  double a;
  double b;
};

double modulus( struct complex c );

int main(){
  struct complex aComplex;
  aComplex.a= 2.3;
  aComplex.b= 5.7;
  printf( "module: %lf\n", modulus(aComplex) );
  return 0;
}

double modulus( struct complex c ){
  return sqrt( c.a*c.a + c.b*c.b );
}