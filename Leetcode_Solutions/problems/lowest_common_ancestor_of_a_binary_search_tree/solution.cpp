/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void findPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path){
        if(!root)return;
        path.push_back(root);
        if(root->val==p->val)return;
        if(root->val>p->val)
            findPath(root->left,p,path);
        else
            findPath(root->right,p,path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1, path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        int i =0,j=0;
        TreeNode* ans;
        while(i<path1.size() && j<path2.size() && path1[i]==path2[j]){
            i++;
            j++;
        }
        ans = path1[i-1];
        return ans;
    }
};