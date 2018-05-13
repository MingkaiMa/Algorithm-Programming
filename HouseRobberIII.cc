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
    
    vector<int> robCore(TreeNode* root)
    {
        vector<int> res(2, 0);
        
        if(root == nullptr)
            return res;
        vector<int> leftRes = robCore(root->left);
        vector<int> rightRes = robCore(root->right);
        res[0] = leftRes[1] + rightRes[1] + root->val;
        res[1] = max(leftRes[0], leftRes[1]) + max(rightRes[0], rightRes[1]);
        return res;
    }
    
    
    int rob(TreeNode* root) {
        
        vector<int> res= robCore(root);
        return max(res[0], res[1]);
    }
};
