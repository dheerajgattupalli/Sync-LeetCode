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
    void recFun(TreeNode *root, int currMax, int currMin, int &ans){
        if(!root)return;
        ans = max(ans, abs(root->val-currMax));
        ans = max(ans, abs(root->val-currMin));
        recFun(root->left, max(root->val, currMax), min(root->val,currMin), ans);
        recFun(root->right, max(root->val, currMax), min(root->val,currMin), ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        recFun(root, root->val, root->val, ans);
        return ans;
    }
};