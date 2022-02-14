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
    void recFun(TreeNode *root, int curr, int &ans){
        if(!root)return;
        ans=max(ans, curr);
        recFun(root->left, curr+1, ans);
        recFun(root->right,curr+1, ans );
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        recFun(root, 1, ans);
        return ans;
    }
};