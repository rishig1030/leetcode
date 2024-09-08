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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }
        
        if(length<k){
            temp = head;
            v.push_back(head);
            
            while(temp){
                ListNode* forward = temp->next;
                temp->next = NULL;
                temp = forward;
                v.push_back(forward);
            }
            while(v.size()<k){
                v.push_back(NULL);
            }
        }
        else{
            int parts = length/k;
            int extra = length%k;
            ListNode* temp = head;
            v.push_back(head);
            while(temp){
                if(extra>0){
                    
                    extra--;
                    int count = 0;
                    while(count<parts && temp->next){
                        temp=temp->next;
                        count++;
                    }
                }
                else{
                    int count = 0;
                    while(count<parts-1 && temp->next){
                        temp=temp->next;
                        count++;
                    }
                }
                
                ListNode* forward = temp->next;
                temp->next = NULL;
                temp = forward;
                if(forward!=NULL)
                v.push_back(forward);
            }
        }
        return v;
    }
};