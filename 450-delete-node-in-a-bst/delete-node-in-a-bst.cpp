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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        else if(root->val == key){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(root->left != NULL && root->right!= NULL){
                int mini = -1;
                TreeNode* temp = root->right;
                while(temp){
                    mini = temp->val;
                    temp = temp->left;
                }
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        else {
            root->right = deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};