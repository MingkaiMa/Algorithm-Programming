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
    
    ListNode* phead;
    
    void reverseListCore()
    {
        if(phead == nullptr)
            return;
        
        if(phead->next == nullptr)
            return;
        
        ListNode* node = phead;
        
        while(node->next->next)
            node = node->next;
        

        ListNode* lastNode = node->next;
        node->next = nullptr;
        
        reverseListCore();
        lastNode->next = phead;
        phead = lastNode; 

    }
    

    ListNode* reverseList(ListNode* head) {
        phead = head;
        reverseListCore();
        return phead;
    }
};
