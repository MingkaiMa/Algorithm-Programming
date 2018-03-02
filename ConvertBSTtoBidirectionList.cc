#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* Convert(BinaryTreeNode* root)
{
    BinaryTreeNode* pLastNodeInList = NULL;
    ConvertNode(root, &pLastNodeInList);

    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while(pHeadOfList != NULL && pHeadOfList->left != NULL)
        pHeadOfList = pHeadOfList->left;

    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == NULL)
        return;

    BinaryTreeNode* pCurrent = pNode;

    if(pCurrent->left != NULL)
        ConvertNode(pCurrent->left, pLastNodeInList);

    pCurrent->left = *pLastNodeInList;
    if(*pLastNodeInList != NULL)
        (*pLastNodeInList)->right = pCurrent;

    *pLastNodeInList = pCurrent;

    if(pCurrent->right != NULL)
        ConvertNode(pCurrent->right, pLastNodeInList);
}