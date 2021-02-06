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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> level1;
        level1.push(root);
        vector<int> ans;
        if(!root)return ans;
        while(!level1.empty()){
            TreeNode *curr = level1.back();
            ans.push_back(curr->val);
            queue<TreeNode *> level2;
            while(!level1.empty()){
                curr = level1.front();
                if(curr->left)level2.push(curr->left);
                if(curr->right)level2.push(curr->right);
                level1.pop();
            }
            cout<<level2.size()<<endl;
            level1 = level2;
        }
        return ans;
    }
};