#include <iostream>
using namespace std;

long long recursive_fibonacci(int n)
{

    if(n >= 2)
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);

    return n;

}


long long iterative_fibonacci(int n)
{

    if(n < 2)
    {
        return n;
    }


    long long previous = 0;
    long long current = 1;
    long long final_result = 0;

    for(int i = 2; i <= n; i++)
    {
        final_result = previous + current;

        previous = current;
        current = final_result;
    }

    return final_result;



}

int main()
{
    cout << recursive_fibonacci(40) << "\n";
    cout << iterative_fibonacci(40) << "\n";

}