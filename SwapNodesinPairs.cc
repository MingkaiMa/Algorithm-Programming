#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode* curr = head;
        ListNode* new_head = curr->next;


        ListNode* new_start = new_head->next;
        new_head->next = curr;

        ListNode* preNode = curr;


        if(new_start == NULL)
        {

            curr->next = NULL;
        }

        while(new_start != NULL && new_start->next != NULL)
        {

            ListNode* next_node = new_start->next;
            ListNode* next_next_node = next_node->next;

            preNode->next = next_node;
            next_node->next = new_start;

            preNode = new_start;
            new_start = next_next_node;

        }

        preNode->next = new_start;


        return new_head;
    }
};


int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node54 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node54;

    Solution sol;
    ListNode* node5 = sol.swapPairs(node1);
    cout << node5->val << "\n";
    cout << node5->next->val << "\n";
    cout << node5->next->next->val << "\n";
    cout << node5->next->next->next->val << "\n";
    cout << node5->next->next->next->next->val << "\n";


}