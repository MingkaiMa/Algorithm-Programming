class Solution {
public:
    
    bool isOneDiff(string word1, string word2)
    {
        if(word1.size() != word2.size())
            return false;
        
        int count = 0;
        int i = 0, j = 0;
        
        while(i < word1.size() && j < word2.size())
        {
            if(word1[i] != word2[j])
                count++;
            i++;
            j++;
        }
        
        return count == 1;
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        
        //corner case: don't forget
        
        //
        
        vector<vector<string>> res;
        
        if(wordList.size() <= 0 || beginWord.size() == 0 || endWord.size() == 0)
        {
            return {};
        }
        
        stack<vector<string>> Stack;
        vector<string> L = {beginWord};
        Stack.push(L);
        
        while(!Stack.empty())
        {
        
            
            vector<string> currList = Stack.top();
            Stack.pop();
            if(currList.back() == endWord)
            {
                res.push_back(currList);
                continue;
            }            
            
            
            string lastWord = currList.back();
            //cout << "Lastword: " << lastWord << "\n";
            

                
            for(auto s: wordList)
            {

                if(isOneDiff(s, lastWord))
                {
                    if(find(currList.begin(), currList.end(), s) != currList.end())
                    {
                        continue;
                    }
                    //cout << "here\n s: " << s << "\n";
                    vector<string> tempList = currList;
                    tempList.push_back(s);
                    Stack.push(tempList);
                    // for(int i = 0; i < tempList.size(); i++)
                    //     cout << tempList[i] << ", ";
                    // cout << "\n";
                }
            }
                        
        }

        if(res.size() == 0)
            return res;
        
        int minLength = res[0].size();
        vector<vector<string>>  rres;
        
        for(auto sv: res)
        {
            if(sv.size() < minLength)
                minLength = sv.size();
        }
        
        for(auto sv: res)
        {
            if(sv.size() == minLength)
                rres.push_back(sv);
        }
        
        
        
        return rres;
    }
};
