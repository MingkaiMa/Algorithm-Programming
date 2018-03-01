#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
}


ListNode* reverseList(ListNode* head)
{
    ListNode* reverseHead = NULL;
    ListNode* node = head;
    ListNode* preNode = NULL;

    while(node != NULL)
    {
        ListNode* next_node = node->next;

        if(next_node == NULL)
        {
            reverseHead = node;
        }

        node->next = preNode;
        preNode = node;
        node = next;

    }

    return reverseHead;
}