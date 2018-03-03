#include <iostream>
#include <string>
using namespace std;

int getTranslationCountAid(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count;

    for(int i = length - 1; i >= 0; i--)
    {
        count = 0;
        if(i < length - 1)
            count = counts[i + 1];

        else
            count = 1;

        if(i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;

            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }


    for(int i = 0; i < length; i++)
    {
        cout << counts[i] << ",";
    }
    cout << "\n";

    count = counts[0];
    delete[] counts;

    return count;
}

int getTranslationCount(int number)
{
    if(number < 0)
        return 0;

    string numberInString = to_string(number);
    return getTranslationCountAid(numberInString);
}




int main()
{
    int n = 12258;
    std::cout << getTranslationCount(n) << "\n";
}