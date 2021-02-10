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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *new_root = root;
        int curr =0;
        createGreaterTreeRecur(root, &curr);
        return root;
    }
    void createGreaterTreeRecur(TreeNode *root, int *curr){
        if(!root)return;
        createGreaterTreeRecur(root->right,curr);
         //cout<<root->val<<' ';
        *curr+=root->val;
        root->val = *curr;
        //cout<<root->val<<endl;
        createGreaterTreeRecur(root->left, curr);
    }
};