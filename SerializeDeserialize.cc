#include <iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void Serialize(BinaryTreeNode* root, ostream& stream)
{
    if(root == NULL)
    {
        stream << "$";
        return;
    }

    stream << root->value << ",";
    Serialize(root->left, stream);
    Serialize(root->right, stream);
}

void Deserialize(BinaryTreeNode** root, istream& stream)
{
    int number;
    if(ReadStream(stream, &number))
    {
        *root = new BinaryTreeNode();
        (*root)->value = number;
        (*root)->left = NULL;
        (*root)->right = NULL;

        Deserialize(&((*root)->left), stream);
        Deserialize(&((*root)->right), stream);

    }
}