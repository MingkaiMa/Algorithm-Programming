#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s = "barfoothefoobarman";
    string word = "foo";

    vector<size_t> positions;

    size_t pos = s.find(word, 0);

    while(pos != string::npos)
    {
        positions.push_back(pos);
        pos = s.find(word, pos + 1);
    }


    for(int i = 0; i < positions.size(); i++)
    {
        cout << positions[i] << ", ";
    }

    cout << "\n";

}

