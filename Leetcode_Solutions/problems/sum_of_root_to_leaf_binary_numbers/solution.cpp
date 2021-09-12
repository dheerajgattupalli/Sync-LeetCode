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
    int strtoint(string s)
    {
        int n = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')n+= pow(2, s.size()-1-i);
        }
        return n;
    }
    void sumRootRec(TreeNode *root, int& ans, string curr){
        if(!root){
            return;
        }
        curr.push_back(root->val?'1':'0');
        if(!root->left && !root->right){
            ans+=strtoint(curr);
            //cout<<curr<<' '<< strtoint(curr)<<endl;
        }
        sumRootRec(root->left, ans, curr);
        sumRootRec(root->right, ans, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        sumRootRec(root, ans, "");
        return ans;
    }
};