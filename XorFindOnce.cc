#include <iostream>
using namespace std;


//  http://blog.csdn.net/xy913741894/article/details/52145043
int FindNumAppearOnce(int data[], int length)
{
    int ret = 0;
    for(int i = 0; i < length; i++)
        ret ^= data[i];

    return ret;
}

int main()
{
    int data[] = {1, 1, 2, 4, 3, 3, 4};
    cout << FindNumAppearOnce(data, 7) << "\n";
}