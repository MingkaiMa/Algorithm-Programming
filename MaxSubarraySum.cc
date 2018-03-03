#include <iostream>

int MaxSubarraySum(int* data, int nLength)
{
    if(data == NULL || nLength <= 0)
        return 0;

    int max_ending_here = data[0];
    int max_so_far = data[0];

    for(int i = 1; i < nLength; i++)
    {
        if(data[i] > (max_ending_here + data[i]))
        {
            max_ending_here = data[i];
        }
        else if(data[i] <= (max_ending_here + data[i]))
        {
            max_ending_here = max_ending_here + data[i];
        }


        if(max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }


    }

    return max_so_far;
}

int main()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    std::cout << MaxSubarraySum(data, 8) << "\n";

}