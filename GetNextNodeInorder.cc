##include <iostream>


struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
};


BinaryTreeNode* getNextNode(BinaryTreeNode* node)
{
    if(node == NULL)
        return NULL;

    BinaryTreeNode* next_node = NULL;


    //situation 1:
    if(node->right != NULL)
    {
        BinaryTreeNode* right_tree = node->right;
        while(right_tree->left != NULL)
        {
            right_tree = right_tree->left;
        }

        next_node = right_tree;


    }

    //situation 2:
    else if(node->parent != NULL)
    {
        BinaryTreeNode* curr = node;
        BinaryTreeNode* parent = node->parent;

        while(parent != NULL && curr == parent->right)
        {
            curr = parent;
            parent = parent->parent;
        }
        next_node = parent;
    }

    return next_node;


}