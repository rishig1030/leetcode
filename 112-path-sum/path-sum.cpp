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
private:
    bool hasPathSum1(TreeNode* root,int targetSum){
        if(root == NULL) return false;
        if(targetSum==root->val && root->left==NULL && root->right==NULL) return true;
        
        return hasPathSum1(root->left,targetSum-root->val) || hasPathSum1(root->right,targetSum-root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->val == targetSum && (root->left==NULL ^ root->right==NULL)) return false;
        return hasPathSum1(root,targetSum);
    }
};