#include <iostream>
#include <map>
using namespace std;



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;

        if(s.size() == 0 || words.size() == 0)
        {
            return res;
        }

        int size_word = words[0].size();
        int word_count = words.size();

        int size_words = size_word * word_count;



        if(size_words > s.size())
            return res;

        map<string, int> hash_map;

        for(int i = 0; i < word_count; i++)
            hash_map[words[i]]++;

        for(int i = 0; i <= s.size() - size_words; i++)
        {
            map<string, int> temp_hash_map(hash_map);

            int j = i;

            while(j < i + size_words)
            {
                string word = s.substr(j, size_word);

                if(hash_map.find(word) == hash_map.end())
                {
                    break;
                }
                else
                {
                    temp_hash_map[word]--;
                }

                j += size_word;
            }
            int count = 0;
            for(auto it = temp_hash_map.begin(); it != temp_hash_map.end(); it++)
            {
                if(it->second > 0)
                    count++;
            }

            if(count == 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{

    map<char, int> m;
    for(char i = 'a'; i < 'd'; i++)
    {
        m[i]++;
    }


    cout << m['a'] << "\n";


    map<char, int> mm(m);

    mm['b']++;
    cout << mm['b'] << "\n";

}