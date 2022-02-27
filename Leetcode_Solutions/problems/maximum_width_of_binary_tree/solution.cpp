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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        int ans = 0,depth=0;
        while(!q.empty()){
            int qsize = q.size();
            int lshift=INT_MAX,rshift=INT_MIN;
            int start = q.front().second;
            while(qsize--){
                pair<TreeNode*,long long int> temp = q.front();
                TreeNode *currNode = temp.first;
                int shift = temp.second-start;
                lshift=min(shift,lshift);
                rshift=max(shift,rshift);
                q.pop();
                if(currNode->right){
                    q.push(make_pair(currNode->right,2*shift+1));
                }
                if(currNode->left){
                    q.push(make_pair(currNode->left,2*shift));
                }
            }
            ans = max(ans, (rshift-lshift)+1);
            depth++;
        }
        return ans;
    }
};