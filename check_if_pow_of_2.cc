#include <iostream>

bool check(int n)
{
    return (n & (n - 1)) == 0;

}


int main(){

    std::cout << check(1024) << "\n";
}