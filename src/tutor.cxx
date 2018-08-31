// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "inc/TutorialConfig.hpp"
#ifdef USE_MYMATH
#include "../mathFunctions/mathFunctions.hpp"
#endif

int main (int argc, char *argv[])
{
	fprintf(stdout,"%s Version %d.%d\n --=============--\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
  fprintf(stdout,"The Mymath square root of %g is %g\n",
	  inputValue, outputValue);
#else
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The Std square root of %g is %g\n",
          inputValue, outputValue);
#endif
  return 0;
}
