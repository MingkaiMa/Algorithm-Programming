/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while(curr && curr->next != nullptr)
        {
            if(curr->next->val == val)
            {
                curr->next = curr->next->next;
                continue;

            }
            curr = curr->next;
            if(curr == nullptr)
                break;
        }
        
        return dummy->next;
        
    }
};
