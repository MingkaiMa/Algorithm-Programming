#include <iostream>

struct BinaryTreeNode
{
    double value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

bool Equal(double n1, double n2)
{
    if((n1 - n2 > -0.0000001) && (n1 - n2 < 0.0000001))
        return true;

    return false;
}

bool hasSubtree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    bool result = false;

    if(root1 != NULL && root2 != NULL)
    {
        if(Equal(root1->value, root2->value))
            result = DoesTree1HasTree2(root1, root2);

        if(!result)
            result = hasSubtree(root1->left, root2);

        if(!result)
            result = hasSubtree(roo1->right, root2);

    }

    return result;
}


bool DoesTree1HasTree2(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(root2 == NULL)
        return true;

    if(root1 = NULL)
        return false;

    if(!Equal(root1->value, root2->value))
        return false;

    return DoesTree1HasTree2(root1->left, root2->left) && DoesTree1HasTree2(root1->right, root2->right);
}

