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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        if(head->next == nullptr)
            return head;
        
        if(head->next->next == nullptr)
        {
            ListNode* newHead = head->next;
            newHead->next = head;
            head->next = nullptr;
            head = newHead;
            return head;
        }
        
        ListNode* preNode = head;
        ListNode* curr = head->next;
        
        
        preNode->next = nullptr;
        
        while(true)
        {
            ListNode* nextNode = curr->next;
            curr->next = preNode;
            preNode = curr;
            if(nextNode == nullptr)
                break;
            curr = nextNode;
            
        }
        
        head = curr;
        return head;
        
    }
};
