#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


int TreeDepth(BinaryTreeNode* root)
{

    if(root == NULL)
    {
        return 0;
    }


    int leftDepth = 1 + TreeDepth(root->left);
    int rightDepth = 1 + TreeDepth(root->right);

    int length = -1;
    if(leftDepth > rightDepth)
        length = leftDepth;

    else
        length = rightDepth;

    return length;
}

bool isBalanced(BinaryTreeNode* root)
{
    if(root == NULL)
        return true;

    int leftDepth = TreeDepth(BinaryTreeNode->left);
    int rightDepth = TreeDepth(BinaryTreeNode->right);

    int diff = abs(leftDepth - rightDepth);
    if(diff > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}