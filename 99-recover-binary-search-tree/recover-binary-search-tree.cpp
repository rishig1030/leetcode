/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* previous;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* second;
    void recover(TreeNode* root){
        if(!root) return ;
        recover(root->left);
        if(previous != NULL && root->val < previous->val){
            if(!first) {
                first = previous;
                middle = root;
            }
            else{
                second = root;
            }
        }
        previous = root;
        recover(root->right);
    }
    void recoverTree(TreeNode* root) {
        previous = new TreeNode(INT_MIN);
        first=middle=second = NULL;
        recover(root);
        if(first && second){
            swap(first->val,second->val);
        }
        else if(first && middle) swap(first->val,middle->val);
    }
};