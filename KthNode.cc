#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* KthNodeCore(BinaryTreeNode* root, unsigned int& k)
{
    BinaryTreeNode* target = NULL;

    if(root->left != NULL)
        target = KthNodeCore(root->left, k);

    if(target == NULL)
    {
        if(k == 1)
            target = root;

        k--;
    }

    if(target == NULL && root->right != NULL)
        target = KthNodeCore(root->right, k);
    
    return target;
}

BinaryTreeNode* KthNode(BinaryTreeNode* root, unsigned int k)
{
    if(root == NULL || k == 0)
        return NULL;

    return KthNodeCore(root, k);
}
