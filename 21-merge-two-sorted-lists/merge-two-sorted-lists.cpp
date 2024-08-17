/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        while(list1 && list2){
            if(list1->val < list2->val){
                ListNode* n1 = new ListNode(list1->val);
                if(temp == NULL) {
                    temp = n1;
                    head = temp;
                } 
                else{
                    temp->next = n1;
                    prev = temp; 
                    temp = n1;
                }
                list1 = list1->next;
            }
            else{
                ListNode* n1 = new ListNode(list2->val);
                if(temp == NULL) {
                    temp = n1;
                    head = temp;
                } 
                else{
                    temp->next = n1;
                prev = temp; 
                temp = n1;
                }
                list2 = list2->next;
            }
        }

        while(list1){
            ListNode* n1 = new ListNode(list1->val);
            if(temp == NULL) {
                temp = n1;
                head = temp;
            } 
            else{
                temp->next = n1;
                prev = temp; 
                temp = n1;
            }
            list1 = list1->next;
        }
        while(list2){
            ListNode* n1 = new ListNode(list2->val);
            if(temp == NULL) {
                temp = n1;
                head = temp;
            } 
            else{
                temp->next = n1;
                prev = temp; 
                temp = n1;
            }
            list2 = list2->next;
        }
        return head;
    }
};