#include "Addition.hpp"
#include "Multiply.hpp"

#include <stdio>

int int main()
{
    int x = 4;
    int y = 5;
    int res = Addition::twoValues(x, y);
    printf("\nAddition Res: %d\n", res);
    res = Multiply::twoValues(x, y);
    printf("\nMultiply Res: %d\n", res);

//    delete corporation;
    
    return 0;
}
