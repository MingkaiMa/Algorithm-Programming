#include <iostream>
#include <vector>
using namespace std;


bool duplicate(int *data, int length, int* duplicate_value)
{
    if(data == NULL || length <= 0)
    {
        return false;
    }

    for(int i = 0; i < length; i++)
    {
        if(data[i] < 0 || data[i] >= length)
        {
            return false;
        }
    }


    //cout << "****\n";
    for(int i = 0; i < length; i++)
    {
        //cout << "i is: " << i << "\n";
        while(data[i] != i)
        {
            if(data[data[i]] == data[i])
            {
                cout << "ues\n";
                *duplicate_value = data[i];
                return true;
            }


            int temp = data[i];
            //cout << "temp is: " << temp << "\n";
            data[i] = data[temp];
            data[temp] = temp;


        }
    }

    return false;


}

int main(){


    //corner case:


    int data[] = {};

    int n = 0;
    int* dup = &n;

    cout << duplicate(data, 0, dup) << "\n";
    cout << *dup << "\n";

    
    //regular case:
//    int data[] = {2, 3, 1, 0, 2, 5, 3};
//
//    int n = 0;
//    int* dup = &n;
//
//    cout << duplicate(data, 7, dup) << "\n";
//    cout << *dup << "\n";
}
