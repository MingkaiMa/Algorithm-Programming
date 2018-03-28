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
    
    TreeNode* getSuccessor(TreeNode* node)
    {
        TreeNode* curr = node;
        if(node->right != nullptr)
        {
            curr = node->right;
            while(curr->left != nullptr)
                curr = curr->left;
        }
        return curr;
    }
    
    TreeNode* getPredecessor(TreeNode* node)
    {
        TreeNode* curr = node;
        if(node->left != nullptr)
        {
            curr = node->left;
            while(curr->right != nullptr)
                curr = curr->right;
        }
        return curr;
    }
    
    void recurCore(TreeNode* node, vector<TreeNode*>& res)
    {
        
    
        if(res.size() == 2)
            return;
        
        if(node == nullptr)
            return;
        
    
        cout << "Node is: " << node->val << "\n";
        
        if(node->left != nullptr&& node->right != nullptr)
        {
            TreeNode* pre = getPredecessor(node);
            TreeNode* successor = getSuccessor(node);
            
            cout << pre->val << "\n";
            cout << successor->val << "\n";
            
            
            if(node->left->val >= node->val && node->right->val <= node->val)
            {
                res.push_back(node->left);
                res.push_back(node->right);
                return;
            }
            
            if(node->left->val >= node->val)
            {
                res.push_back(node->left);
            }
            
            else if(node->right->val <= node->val)
            {
                res.push_back(node->right);
            }
            
            
            else if(pre->val >= node->val && successor->val <= node->val)
            {
                res.push_back(pre);
                res.push_back(successor);
                return;
            }
            
            else if(pre->val >= node->val)
            {
                res.push_back(pre);

            }
            
            else if(successor->val <= node->val)
            {
                res.push_back(successor);
            }
            
            recurCore(node->left, res);
            recurCore(node->right, res);
        }
        
        else if(node->left != nullptr)
        {
            
            TreeNode* pre = getPredecessor(node);
            
            if(node->left->val >= node->val)
            {
                res.push_back(node->left);
            }
            
            else if(pre->val >= node->val)
            {
                res.push_back(pre);
            }
            
            recurCore(node->left, res);
        }
        else if(node->right != nullptr)
        {
            TreeNode* successor = getSuccessor(node);
            if(node->right->val <= node->val)
            {
                res.push_back(node->right);
            }
            else if(successor->val <= node->val)
            {
                res.push_back(successor);
            }
            
            recurCore(node->right, res);        
        }
    }
    
    void recoverTree(TreeNode* root){
        
        vector<TreeNode*> res;
        recurCore(root, res);
        
        
        cout << "***\n";
        for(int i = 0; i < res.size(); i++)
            cout << res[i]->val << "\n";
        
        
        cout << "====\n";
        cout << res.size() << "\n";
        if(res.size() == 2)
        {
            int temp = res[0]->val;
            res[0]->val = res[1]->val;
            res[1]->val = temp;
        }
        
        
    }
};
