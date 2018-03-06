#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

bool isBalanced(BinaryTreeNode* root, int* pDepth)
{
    if(root == NULL)
    {
        *pDepth = 0;
        return true;
    }

    int left, right;

    if(isBalanced(root->left, &left) && isBalanced(root->right, &right))
    {
        int diff = abs(left - right);
        if(diff <= 1)
        {
            *pDepth = 1 + (left > right ? left: right);
            return true;
        }
    }

    return false;
}

bool isBalancedMain(BinaryTreeNode* root)
{
    int depth = 0;
    return isBalanced(root, &depth);
}