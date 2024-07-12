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
private:
    void inserting(ListNode* &head,ListNode* &tail,int data){
        ListNode* node = new ListNode(data);
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = 0;
        int carry = 0;
        ListNode* first = l1;
        ListNode* second = l2;
        
        ListNode* sumhead = NULL;
        ListNode* sumtail = NULL;
        
        
        while(first || second){
            
            if(first != NULL && second != NULL){
                s = (first->val + second->val + carry)%10;
                carry = (first->val + second->val + carry)/10;
                first = first->next;
                second = second->next;
            }
            else if(first != NULL && second == NULL){
                s = (first->val + carry)%10 ;
                carry = (first->val + carry)/10 ;
                first = first->next; 
            }
            else{
                s = (second->val + carry)%10;
                carry = (second->val + carry)/10;
                second = second->next; 
            }
            inserting(sumhead,sumtail,s);
        }
        if(carry){
            inserting(sumhead,sumtail,carry);
        }
        return sumhead;
    }
};