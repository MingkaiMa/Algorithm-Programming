#include <iostream>
#include <stack>

using namespace std;

bool isPopOrder(const int* push_list, const int* pop_list, int length)
{
    bool flag = false;
    if(push_list != NULL && pop_list != NULL && length > 0)
    {
        const int* next_push = push_list;
        const int* next_pop = pop_list;

        stack<int>stackData;

        while(next_pop - pop_list < length)
        {
            while(stackData.empty() || stack.top() != *next_pop)
            {
                if(next_push - push_list == length)
                {
                    break;
                }

                stackData.push(*next_push);
                next_push++;
            }

            if(stackData.top() != *next_pop)
                break;

            stackData.pop();
            next_pop++;
        }

        if(stackData.empty() && next_pop - pop_list == length)
            flag = true;
    }

    return flag;
}