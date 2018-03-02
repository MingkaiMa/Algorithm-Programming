#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


void PrintZigZag(BinaryTreeNode* root)
{
    if(root == NULL)
        return;

    stack<BinaryTreeNode*>levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(root);

    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* node = levels[current].top();
        levels[current].pop();

        cout << p->value << " ";

        if(current == 0)
        {
            if(node->left != NULL)
                levels[next].push(node->left);

            if(node->right != NULL)
                levels[next].push(node->right);
        }
        else
        {
            if(node->right != NULL)
                levels[next].push(node->right);

            if(node->left != NULL)
                levels[next].push(node->left);
        }

        if(levels[current].empty())
        {
            cout << "\n";
            current = 1 - current;
            next = 1 - next;
        }
    }

}