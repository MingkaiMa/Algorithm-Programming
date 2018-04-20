#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int reverseBits(int n)
{
    vector<int> bit(32, 0);
    //int j = 0;
    for(int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        //j++;
        if(n & mask)
            bit[i] = 1;
    }

    for(auto i: bit)
        cout << i << ", ";
    cout << endl;


//    int count = 0;
//    int nn = n;
//    while(nn)
//    {
//        nn = nn >> 1;
//        count++;
//    }
//
//    cout << count << endl;


    int res = 0;

    for(int i = 0; i < count; i++)
    {
        res += pow(2, count - 1 - i) * bit[i];
    }

    cout << res << endl;
    return 1;
}

int main()
{
    int n = 1;
    reverseBits(n);
}