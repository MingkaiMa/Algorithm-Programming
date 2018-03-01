/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    two pass solution
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int l = 1;
        ListNode* curr = head;
        while(curr->next != NULL){
            l += 1;
            curr = curr->next;
        }

        cout << l << "\n";

        if(l == n){
            head = head->next;
            return head;
        }


        int inde = l - n;

        curr = head;
        while(curr->next != NULL && inde > 1){
            inde -= 1;
            curr = curr->next;

        }

        curr->next = curr->next->next;
        return head;

    }
};


/*
    only one pass solution
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* aid_node = new ListNode(0);
        aid_node->next = head;

        ListNode* curr = aid_node;
        ListNode* front = aid_node;

        for(int i = 0; i <= n; i++)
        {
            front = front->next;
        }



        while(front != NULL){
            front = front->next;
            curr = curr->next;
        }

        curr->next = curr->next->next;
        return aid_node->next;


    }
};