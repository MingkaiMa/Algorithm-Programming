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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL || k <= 0)
            return NULL;

        if(k == 1)
            return head;

        int countLength = 0;
        ListNode* countNode = head;
        while(countNode != NULL)
        {
            countLength++;
            countNode = countNode->next;
        }

        if(countLength < k)
        {
            return head;
        }


        ListNode* curr = head->next;
        ListNode* preNode = head;

        int length = 1;

        ListNode* prepreNode = preNode;

        while(length < k)
        {
            ListNode* next_node = curr->next;
            curr->next = preNode;
            preNode = curr;
            curr = next_node;
            length++;
        }

        int count = 1;
        ListNode* testCurr = curr;
        while(count < k && testCurr != NULL)
        {
            count++;
            testCurr = testCurr->next;
        }

        if(testCurr == NULL)
        {
            prepreNode->next = curr;
            head = preNode;
            return head;
        }


        head = preNode;
        prepreNode->next = reverseKGroup(curr, k);

        return head;

    }
};