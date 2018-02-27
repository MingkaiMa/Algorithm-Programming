#include <iostream>
#include <stack>
using namespace std;


//Approach 1: use stack

int printListinReverseOrder_stack(ListNode* head)
{
    stack<ListNode*> list_nodes;
    ListNode* curr = head;
    while(curr != NULL)
    {
        list_nodes.push(curr);
        curr = curr->next;
    }

    while(!list_nodes.empty())
    {
        cout << list_nodes.top()->value << "\n";
        list_nodes.pop();
    }
}




//Approach 2: recursion

int printListinReverseOrder_recur(ListNode* head)
{
    if(head != NULL)
    {
        if(head->next != NULL)
        {
            printListinReverseOrder_recur(head->next);
        }

        cout << head->value;
    }
}