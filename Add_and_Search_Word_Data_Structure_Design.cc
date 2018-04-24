class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode(): isWord(false)
    {
        for(auto& a: children)
            a = nullptr;
    }
};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(auto& a: word)
        {
            int i = a - 'a';
            if(!p->children[i])
                p->children[i] = new TrieNode();
            p = p->children[i];
        }
        
        p->isWord = true;
    }
    
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchCore(word, root, 0);
    }
    
    bool searchCore(string& word, TrieNode* p, int i)
    {
        if(i == word.size())
            return p->isWord;
        
        if(word[i] == '.')
        {
            for(auto& a: p->children)
            {
                if(a && searchCore(word, a, i + 1))
                    return true;
            }
            return false;
        }
        else
        {
            return p->children[word[i] - 'a'] && searchCore(word, p->children[word[i] - 'a'], i + 1);
        }
    }
    
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
