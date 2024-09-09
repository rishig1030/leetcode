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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m,vector<int> (n,-1));
        ListNode* temp = head;
        int direction = 0;
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        while(temp){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    if(temp==NULL) return v;
                    v[top][i] = temp->val;
                    temp=temp->next;
                }
                top++;
            }
            else if(direction==1){
                for(int i=top;i<=bottom;i++){
                    if(temp==NULL) return v;
                    v[i][right] = temp->val;
                    temp=temp->next;
                }
                right--;
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){
                    if(temp==NULL) return v;
                    v[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }
            else {
                for(int i=bottom;i>=top;i--){
                    if(temp==NULL) return v;
                    v[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return v;
    }
};