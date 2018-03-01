/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {


        if(!head || !head->next){
            return head;
        }

        if(!head->next->next){

            ListNode* new_head = head->next;
            new_head->next = head;
            new_head->next->next = NULL;
            return new_head;
        }


        ListNode* new_head = head->next;

        ListNode* curr = head;


        while(1){
            cout << "asdfa\n";
            ListNode* next_node = curr->next->next;
            cout << next_node->val << "\n";
            curr->next->next = curr;

            if(next_node == NULL){
                return new_head;
            }

            if(next_node->next == NULL){
                cout << "pp\n";
                curr->next = next_node;
                new_head->next = curr;
                return new_head;
            }

            else{
                cout << "here\n";
                curr->next = next_node->next;
                cout << curr->next->val << "\n";
                curr = next_node;
                cout << curr->val << "\n";
            }


        }

        return new_head;

    }
};



int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;


    //cout << n1->next->val << "\n";
    Solution sol;
    ListNode* s = sol.swapPairs(n1);

    cout << s->val << ", " << s->next->val << ", " << s->next->next->val << ", " <<  "\n";

}