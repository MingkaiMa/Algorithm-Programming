#include <iostream>

struct ListNode
{
    int key;
    ListNode* next;
}

unsigned int GetListLength(ListNode* head)
{
    if(head == NULL)
        return 0;

    unsigned int len = 0;
    ListNode* node = head;

    while(node != NULL)
    {
        len++;
        node = node->next;
    }

    return len;
}

ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2)
{
    unsigned int len1 = GetListLength(head1);
    unsigned int len2 = GetListLength(head2);
    int lenDiff = len1 - len2;

    ListNode* headLong = head1;
    ListNode* headShort = head2;
    if(len2 > len1)
    {
        headLong = head2;
        headShort = head1;
        lenDiff = len2 - len1;
    }


    for(int i = 0; i < lenDiff; i++)
        headLong = headLong->next;

    while(headLong != NULL && headShort != NULL ** headLong != headShort)
    {
        headLong = headLong->next;
        headShort = headShort->next;
    }

    ListNode* res = headLong;

    return res;
}