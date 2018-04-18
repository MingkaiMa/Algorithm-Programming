/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {

        TreeNode* curr = root;
        while(curr != nullptr)
        {
            stack1.push(curr);
            curr = curr->right;
        }
        
        while(!stack1.empty())
        {
            TreeNode* currNode = stack1.top();
            stack1.pop();
            
            stack2.push(currNode);
            
            if(currNode->left != nullptr)
            {
                TreeNode* tempNode = currNode->left;
                while(tempNode->right != nullptr)
                    stack1.push(tempNode);
            }
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack2.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = stack2.top()->val;
        stack2.pop();
        return res;
    }
private:
    stack<TreeNode*> stack1;
    stack<TreeNode*> stack2;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
