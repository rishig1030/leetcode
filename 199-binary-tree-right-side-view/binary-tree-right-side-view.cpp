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
    void rightview(TreeNode* root,int level,vector<int> &v){
        if(!root) return;
        if(level == v.size()) v.push_back(root->val);
        rightview(root->right,level+1,v);
        rightview(root->left,level+1,v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightview(root,0,v);
        return v;
    }
};