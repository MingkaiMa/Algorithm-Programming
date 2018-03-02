#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


void PrintLineByLine(BinaryTreeNode* root)
{
    if(root == NULL)
        return;

    queue<BinaryTreeNode*> Q;
    Q.push(root);
    int nextLevel = 0;
    int toBePrinted = 1;

    while(!Q.empty())
    {
        BinaryTreeNode* toPrintNode = Q.front();
        cout << toPrintNode->value << " ";

        if(toPrintNode->left != NULL)
        {
            Q.push(toPrintNode->left);
            ++nextLevel;
        }

        if(toPrintNode->right != NULL)
        {
            Q.push(toPrintNode->right);
            ++nextLevel;
        }

        Q.pop();
        --toBePrinted;

        if(toBePrinted == 0)
        {
            cout << "\n";
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}