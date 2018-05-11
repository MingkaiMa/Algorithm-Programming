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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        if(head->next == nullptr)
            return head;
        
        if(head->next->next == nullptr)
            return head;
        
        int length = 0;
        
        ListNode* tmp = head;
        
        while(tmp != nullptr)
        {
            length += 1;
            tmp = tmp->next;
        }
        
        
        ListNode* evenHead = head->next;
        
        ListNode* oddCurr = head;
        ListNode* evenCurr = evenHead;
        
        ListNode* curr = evenHead->next;
        
        int count = 1;
        
        while(curr != nullptr)
        {
            if(count % 2)
            {
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            }
            else
            {
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            }
            
            curr = curr->next;
            count += 1;
            
        }
        
        if(length % 2)
            evenCurr->next = nullptr;
        
        
        oddCurr->next = evenHead;
        
        return head;
        
    }
};
