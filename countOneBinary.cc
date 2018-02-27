#include <iostream>


//Approach 1:

int fun(int n)
{
    int count = 0;
    int helper = 1;

    while(helper)
    {
        std::cout << "is: " << helper << "\n";
        if(n & helper)
        {
            count++;
        }

        helper = helper << 1;

    }

    return count;

}


//Approach 2 much faster

int count(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = n & (n - 1);
    }

    return count;


}

int main()
{

    std::cout << count(6) << "\n";

}