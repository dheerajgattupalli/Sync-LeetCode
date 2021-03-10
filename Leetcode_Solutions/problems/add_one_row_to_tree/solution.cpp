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
    TreeNode* recAddRow(TreeNode *root, int v, int d, int curr){
        if(!root)return root;
        TreeNode *temp_1 = root->left,*temp_2 = root->right;
        if(curr==d){
            TreeNode* temp1 = new TreeNode(v),*temp2 = new TreeNode(v);
            temp1->left = root->left;
            temp2->right = root->right;
            root->left = temp1;
            root->right = temp2;
            temp1->left = recAddRow(temp1->left, v, d, curr+1);
            temp2->right = recAddRow(temp2->right, v, d, curr+1);
            return root;
        }
        root->left = recAddRow(temp_1, v, d, curr+1);
        root->right = recAddRow(temp_2, v, d, curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode *ans = new TreeNode(v);
            ans->left = root;
            return ans;
        }
        return recAddRow(root, v, d-1, 1);
    }
};