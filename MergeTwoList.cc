#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
}

//Approach 1: non-recursion

ListNode* merge(ListNode* head1, ListNode* head2)
{

    if(head1 == NULL && head2 == NULL)
        return NULL

    if(head1 == NULL && head2 != NULL)
        return head2;

    if(head1 != NULL && head2 == NULL)
        return head1;


    ListNode* newHead = new ListNode(0);
    ListNode* curr = newHead;

    ListNode* p1 = head1;
    ListNode* p2 = head2;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->value <= p2->value)
        {
            curr->next = p1;
            curr = curr->next;
            p1 = p1->next;
        }

        else if(p1->value > p2->value)
        {
            curr->next = p2;
            curr = curr->next
            p2 = p2->next;
        }
    }

    if(p1 == NULL)
    {
        curr->next = p2;
    }

    else if(p2 == NULL)
    {
        curr->next = p1;
    }

    return curr->next;
}


//Approach 2: recursion

ListNode* mergeRecursion(ListNode* head1, ListNode* head2)
{
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;

    ListNode* mergeHead = NULL;

    if(head1->value < head2->value)
    {
        mergeHead = head1;
        mergeHead->next = mergeRecursion(head1->next, head2);
    }
    else
    {
        mergeHead = head2;
        mergeHead->next = mergeRecursion(head1, head2->next);
    }
    return mergeHead;
}