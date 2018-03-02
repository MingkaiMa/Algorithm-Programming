#include <iostream>

struct ComplexListNode
{
    int value;
    ComplexListNode* next;
    ComplexListNode* sibling;
}


void CloneNodes(ComplexListNode* head)
{
    ComplexListNode* node = head;
    while(node != NULL)
    {
        ComplexListNode* cloned = new ComplexListNode();
        cloned->value = node->value;
        cloned->next = node->next;
        clones->sibling == NULL;

        node->next = cloned;
        node = cloned->next;
    }
}

void ConnectSiblingNodes(ComplexListNode* head)
{
    ComplexListNode* node = head;

    while(node != NULL)
    {
        ComplexListNode* clonedNode = node->next;
        if(node->sibling != NULL)
        {
            clonedNode->sibling = node->sibling->next;
        }
        node = clonedNode->next;
    }
}

ComplexListNode* SplitConnectedNodes(ComplexListNode* head)
{
    ComplexListNode* node = head;
    ComplexListNode* ClonedHead = NULL;
    ComplexListNode* clonedNode = NULL;

    if(node != NULL)
    {
        ClonedHead = clonedNode = node->next;
        node->next = clonedNode->next;
        node = node->next;

    }

    while(node != NULL)
    {
        cloneNodes->next = node->next;
        clonedNode = clonedNode->next;
        node->next = clonedNode->next;
        node = node->next;
    }

    return ClonedHead;
}


ComplexListNode* Clone(ClonedHead* head)
{
    CloneNodes(head);
    ConnectSiblingNodes(head);
    return SplitConnectedNodes(head);
}