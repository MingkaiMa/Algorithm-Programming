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
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(0);
        ListNode* curr_s = start;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;


        while(curr1 != NULL && curr2 != NULL){


//            cout << curr1->val << "\n";
//            cout << curr2->val << "\n";

            if(curr1->val > curr2->val){

                ListNode* new_node = new ListNode(curr2->val);
                curr_s->next = new_node;

                curr2 = curr2->next;
                curr_s = curr_s->next;

            }
            else if(curr1->val < curr2->val){

                ListNode* new_node = new ListNode(curr1->val);
                curr_s->next = new_node;

                curr1 = curr1->next;
                curr_s = curr_s->next;
            }
            else if(curr1->val == curr2->val){

                ListNode* new_node = new ListNode(curr1->val);


                curr_s->next = new_node;
                curr_s = curr_s->next;
                curr_s->next = new_node;
                curr_s = curr_s->next;

                curr1 = curr1->next;
                curr2 = curr2->next;


            }
        }



        while(curr1 != NULL){

            ListNode* new_node = new ListNode(curr1->val);

            curr_s->next = new_node;
            curr1 = curr1->next;
            curr_s = curr_s->next;
        }

        while(curr2 != NULL){
            ListNode* new_node = new ListNode(curr2->val);

            curr_s->next = new_node;
            curr2 = curr2->next;
            curr_s = curr_s->next;
        }
        return start->next;
    }
};


/*
    Recursion
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        if(l1->val < l2->val){
            ListNode* L = l1;
            L->next = mergeTwoLists(l1->next, l2);
            return L;
        }
        else{
            ListNode* L = l2;
            L->next = mergeTwoLists(l1, l2->next);
            return L;
        }
    }
};



int main(){

    //Solution sol;
    ListNode* l1 = new ListNode(1);
    ListNode* l11 = new ListNode(2);
    ListNode* l111 = new ListNode(4);
    l1->next = l11;
    l11->next = l111;

    ListNode* l2 = new ListNode(1);
    ListNode* l22 = new ListNode(3);
    ListNode* l222 = new ListNode(4);
    l2->next = l22;
    l22->next = l222;


    ListNode* save_for1 = l1;

    save_for1->next = l111;

    cout << l1->next->val << "\n";
//    ListNode* R = sol.mergeTwoLists(l1, l2);
//    cout << R->val << ", "<< R->next->val<< "\n";

}