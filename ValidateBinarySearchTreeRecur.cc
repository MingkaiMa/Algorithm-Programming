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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        if(root != nullptr && root->left == nullptr && root->right == nullptr)
            return true;
        
        if(root->left != nullptr && root->val <= root->left->val)
            return false;
        
        if(root->right != nullptr && root->val >= root->right->val)
            return false;
        
        
        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        
        return left && right;
        
        
        
    }
};
