/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<int> res;
        
        
        queue<vector<TreeNode*>> Queue;
        vector<TreeNode*> currList;
        currList.push_back(root);
        Queue.push(currList);
        
        while(!Queue.empty())
        {
            vector<TreeNode*> curr = Queue.front();
            Queue.pop();
            
            cout << curr[0]->val << endl;
            
            res.push_back(curr[0]->val);
            
            vector<TreeNode*> toBePushed;
            
            for(auto& node: curr)
            {
                if(node->right != nullptr)
                    toBePushed.push_back(node->right);
                if(node->left != nullptr)
                    toBePushed.push_back(node->left);
            }
            
            if(toBePushed.size() != 0)
                Queue.push(toBePushed);
            
        }
        
        return res;
    }
};
