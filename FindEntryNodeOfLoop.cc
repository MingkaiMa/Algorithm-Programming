#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
}


ListNode* MeetingNode(ListNode* head)
{
    if(head == NULL)
        return NULL;


    ListNode* slowNode = head->next;


    if(slowNode == NULL)
        return NULL;


    ListNode* fastNode = head->next->next;

    while(fastNode != NULL && slowNode != NULL)
    {
        if(fastNode == slowNode)
            return slowNode;


        slowNode = slowNode->next;

        fastNode = fastNode->next;
        if(fastNode != NULL)
            fastNode = fastNode->next;
    }

    return NULL;
}


ListNode* EntryNodeForLoop(ListNode* head)
{
    ListNode* meetingNode = MeetingNode(head);
    if(meetingNode == NULL)
        return NULL;

    int lenLoop = 1;

    ListNode* temp = meetingNode;
    while(temp->next != meetingNode)
    {
        temp = temp->next;
        lenLoop++;

    }

    temp = head;

    for(int i = 0; i < lenLoop; i++)
        temp = temp->next;

    ListNode* temp2 = head;

    while(temp != temp2)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }

    return temp;
}