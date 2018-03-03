#include <iostream>

int MoreThanHalfNum(int* nums, int length)
{
    if(CheckInvalidArray(nums, length))
        return 0;

    int result = nums[0];
    int times = 1;

    for(int i = 1; i < length; i++)
    {
        if(times == 0)
        {
            result = nums[i];
            times = 1;
        }
        else if(nums[i] == result)
        {
            times++;
        }
        else
        {
            times--;
        }
    }
    if(!CheckMoreThanHalf(nums, length, result))
        return 0;

        
    return result;
}