#include <iostream>

struct BinaryTreeNode
{
    double value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


void mirrorTreeRecursively(BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return;
    }


    BinaryTreeNode* left_tree =root->left;
    BinaryTreeNode* right_tree =root->right;

    root->right = left_tree;
    root->left = right_tree;

    if(root->left)
        mirrorTreeRecursively(root->left);

    if(root->right)
        mirrorTreeRecursively(root->right);
    
}