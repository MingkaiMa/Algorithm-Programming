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