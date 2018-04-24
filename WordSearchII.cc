class Solution {
public:
    
    struct Trie
    {
        vector<Trie*> child;
        bool isWord;
        Trie(): child(vector<Trie*>(26, nullptr)), isWord(false){}
    };
    
    void DFS(vector<vector<char>>& board, Trie* root, int x, int y, string str)
    {
        int row = board.size();
        int col = board[0].size();
        if(!root || board[x][y] == '#') return;
        str += board[x][y];
        if(root->isWord)
        {
            ans.push_back(str);
            root->isWord = false;
        }
        char ch = board[x][y];
        board[x][y] = '#';
        if(x + 1 < row)
            DFS(board, root->child[board[x + 1][y] - 'a'], x + 1, y, str);
        if(x - 1 >= 0)
            DFS(board, root->child[board[x - 1][y] - 'a'], x - 1, y, str);
        if(y + 1 < col)
            DFS(board, root->child[board[x][y + 1] - 'a'], x, y + 1, str);
        if(y - 1 >= 0)
            DFS(board, root->child[board[x][y - 1] - 'a'], x, y - 1, str);
        board[x][y] = ch;          
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0)
            return {};
        Trie* root = new Trie();
        Trie* node;
        for(auto& str: words)
        {
            node = root;
            for(auto& ch: str)
            {
                if(!node->child[ch - 'a'])
                    node->child[ch - 'a'] = new Trie();
                node = node->child[ch - 'a'];
            }
            node->isWord = true;
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
                DFS(board, root->child[board[i][j] - 'a'], i, j, "");
        }
        return ans;
    }
private:
    vector<string> ans;
};
