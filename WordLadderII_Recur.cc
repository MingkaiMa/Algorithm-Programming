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
    
    void findLaddersCore(vector<vector<string>>& res, vector<string>& currList, vector<string>& wordList, string endWord)
    {
        
        string lastWord = currList.back();
        
        if(lastWord == endWord)
        {
            res.push_back(currList);
            return;
        }
        
        for(auto& s: wordList)
        {
            if(isOneDiff(s, lastWord))
            {
                if(find(currList.begin(), currList.end(), s) != currList.end())
                    continue;
                
                currList.push_back(s);
                findLaddersCore(res, currList, wordList, endWord);
                currList.pop_back();
            }
        }
        
        
        
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        
        //corner case: don't forget
        
        //
        
        vector<vector<string>> res;
        
        if(wordList.size() <= 0 || beginWord.size() == 0 || endWord.size() == 0)
        {
            return {};
        }
        
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return {};
        
        
        vector<string> currList = {beginWord};
        findLaddersCore(res, currList, wordList, endWord);

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
