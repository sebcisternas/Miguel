#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

main(int argc, char* argv)
{
   int itera=0;
   double x,y;
   int i,count=0;
   double z;
   double pi;

   printf("Ingrese el numero de iteraciones para estimar pi: ");
   scanf("%d",&itera);

   /* Numeros Aleatorios */
   srand(SEED);
   count=0;
   for ( i=0; i<itera; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/itera*4;
   printf("# Iteraciones= %d , estimado de pi es %g \n",itera,pi);
}

