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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        ListNode* previous = head;
        ListNode* current = head;

        while(current){
            if(current == head && st.find(current->val)!=st.end()){
                ListNode* node = current;
                current = current->next;
                head = current;
                node->next = NULL;
                delete node;
            }
            else if(st.find(current->val) != st.end()){
                ListNode* node = current ;
                current = current->next;
                previous->next = current;
                node->next = NULL;
                delete node;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
        return head;
    }
};