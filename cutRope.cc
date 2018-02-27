#include <iostream>


//Approach 1: dynamic programming

int maxProduct(int length)
{
    if(length < 2)
        return 0;

    if(length == 2)
        return 1;

    if(length == 3)
        return 2;


    int* product = new int[length + 1];

    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;


    int max_product = 0;

    for(int i = 4; i <= length; i++)
    {

        max_product = 0;
        for(int j = 1; j <= i / 2; j++)
        {
            int curr_product = product[j] * product[i - j];
            if(curr_product > max_product)
            {
                 max_product = curr_product;
            }

            product[i] = max_product
        }

    }

    max_product = product[length];
    delete []product;

    return max_product;
}



//Approach 2: greedy algorithm
