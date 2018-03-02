#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


void FindPath(BinaryTreeNode* root, int targetSum, vector<int>& path, int currentSum)
{
    currentSum += root->value;
    path.push_back(root->value);


    bool isLeaf = root->left == NULL && root->right == NULL;

    if(currentSum == targetSum && isLeaf)
    {
        cout << "One path found: \n";
        vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << "\n";
    }


    if(root->left != NULL)
    {
        FindPath(root->left, targetSum, path, currentSum);
    }

    if(root->right != NULL)
    {
        FindPath(root->riht, targetSum, path, currentSum);
    }

    path.pop_back();
}

void findPath(BinaryTreeNode* root, int targetSum)
{
    if(root == NULL)
        return;

    vector<int> path;
    int currentSum = 0;
    FindPath(root, targetSum, path, currentSum);

}