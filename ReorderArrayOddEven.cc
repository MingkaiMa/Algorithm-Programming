#include <iostream>


void Reorder(int* p, int length)
{
    if(p == NULL || length == 0)
    {
        return;
    }

    int *pBegin = p;
    int *pEnd = p + length - 1;


    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && (*pEnd & 1) != 0)
            pBegin++;


        while(pBegin < pEnd && (*pEnd & 1) == 0)
            pEnd--;


        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}