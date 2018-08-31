// mysqrt.hpp
#include "../inc/mathFunctions.hpp"
 
 double mysqrt(double number)
 {
   long i;
   double x2, y;
   const double threehalfs = 1.5F;

   x2 = number * 0.5F;
   y  = number;
   i  = * ( long * ) &y;                     // floating point bit level hacking [sic]
   i  = 0x5f3759df - ( i >> 1 );             // Newton's approximation
   y  = * ( double * ) &i;
   y  = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
   y  = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration
   y  = y * ( threehalfs - ( x2 * y * y ) ); // 3rd iteration

   return (1/y);
}