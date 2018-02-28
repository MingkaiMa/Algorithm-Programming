#include <iostream>



double power(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;

    if(exponent == 1)
        return base;

    double result = power(base, exponent >> 1);

    result = result * result;

    if((exponent & 0x1) == 1)
    {
        result *= base;

    }


    return result;
}


int main()
{
    std::cout << power(2, 5) << "\n";

}