void print(ListNode* head)
{
    if(head == NULL)
        return;

    if(head->next != NULL)
        print(head->next);

    cout << head->value;
}