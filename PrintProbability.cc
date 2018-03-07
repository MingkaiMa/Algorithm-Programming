#include <iostream>
#include <cmath>
using namespace std;

int g_maxValue = 6;


void Probability2(int original, int current, int sum, int* pProbabilities)
{
    if(current == 1)
        pProbabilities[sum - original]++;

    else
    {
        for(int i = 1; i < g_maxValue; i++)
            Probability2(original, current - 1, i + sum, pProbabilities);
    }
}

void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; i++)
    {
        Probability2(number, number, i, pProbabilities);
    }
}

void PrintProbability(int number)
{
    if(number < 1)
        return;


    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; i++)
    {
        pProbabilities[i - number] = 0;
    }

    Probability(number, pProbabilities);

    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; i++)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        cout << i << " %" << ratio * 100<< "\n";
    }

    delete[] pProbabilities;
}

int main()
{
    PrintProbability(3);
}