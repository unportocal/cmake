// mysqrt.hpp
#include "mathFunctions.hpp"

#define EPSILON 1e-10

double mysqrt(double value){
	if(value < 0)
	{
		std::cout << "Error in the input value. Negative input received." << std::endl;
		return -1;
	}
	double a = 1;
	double b = value;
	if(value < 1)
	{
		a = value;
		b = 1;
	}
	double mid = (a + b) / 2;
	double err = mid * mid - value;
	while(fabs(err) > EPSILON)
	{
		if(err > 0)
		{
			b = mid;
		}else{
			a = mid;
		}
		mid = (a + b) / 2;
		err = mid * mid - value;
	}
	return mid;
}