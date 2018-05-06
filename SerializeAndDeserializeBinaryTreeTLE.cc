/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
private:
    int start = 0;
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
        {
            string s = "";
            s += "$,";
            return s;
        }
        
        string s = "";
        s += to_string(root->val);
        s += ",";
        
        string leftS = serialize(root->left);
        string rightS = serialize(root->right);
        
        s += leftS;
        s += rightS;
        
        return s;
    }

    TreeNode* deCore(vector<string> strVec)
    {

        if(strVec[start] == "$")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(strVec[start]));
        
        start++;
        node->left = deCore(strVec);
        
        start++;
        node->right = deCore(strVec);
        
        return node;
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> strVec;
        
        int i = 0;
        while(i < data.size())
        {
            while(data[i] == ',')
                i++;
            
            int j = i;
            while(j < data.size() && data[j] != ',')
                j++;
            
            string tmp = data.substr(i, j - i);
            strVec.push_back(tmp);
            
            i = j;
            if(j == data.size())
                break;
        }
        
        
        return deCore(strVec);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
