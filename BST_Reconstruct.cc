#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


BinaryTreeNode* Reconstruct(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)

        return NULL;

    return Construct_Aid(preorder, preorder + length - 1, inorder, inorder + length - 1);

}

BinaryTreeNode* Construct_Aid(int* startPre, int* endPre, int* startInorder, int* endInorder)
{

    int root_value = startPre[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = root_value;
    root->left = NULL;
    root->right = NULL;

    if(startPre == endPre)
    {
        if(startInorder == endInorder && *startPre == *startInorder)
        {
            return root;
        }
        else
        {
            throw std::exception("Input error");
        }
    }

    int* rootInorder = startInorder;
    while(rootInorder < endInorder && *rootInorder != root_value)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != root_value)
        throw std::exception("Input error")

    int leftLength = rootInorder - startInorder;
    int* leftPreEnd = startPre + leftLength;

    if(leftLength > 0)
    {
        root->left = Construct_Aid(startPre + 1, leftPreEnd, startInorder, rootInorder - 1);
    }

    if(leftLength < endPre - startPre)
    {
        root->right = Construct_Aid(leftPreEnd + 1, endPre, rootInorder + 1, endInorder);
    }

    return root; 
}