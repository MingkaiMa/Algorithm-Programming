#include <iostream>
#include <queue>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void PrintFromTopToBottom(BinaryTreeNode* root)
{

    if(root == NULL)
        return;


    std::queue<BinaryTreeNode*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        BinaryTreeNode* toPrintNode = Q.front();
        std::cout << toPrintNode->value;

        Q.pop();

        if(toPrintNode->left != NULL)
            Q.push(toPrintNode->left);

        if(toPrintNode->right != NULL)
            Q.push(toPrintNode->right);


    }
}