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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q1;
        q1.push(root);
        vector<double> ans;
        while(!q1.empty()){
            queue<TreeNode *> q2;
            int count = q1.size();
            double curr_sum = 0;
            while(!q1.empty()){
                TreeNode *curr = q1.front();
                if(curr->left)q2.push(curr->left);
                if(curr->right)q2.push(curr->right);
                q1.pop();
                curr_sum+=curr->val;
            }
            ans.push_back(curr_sum/count);
            q1 = q2;
        }
        return ans;
    }
};