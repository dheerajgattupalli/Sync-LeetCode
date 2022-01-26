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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        //s1.push(root1);
        //s2.push(root2);
        TreeNode* curr1=root1,*curr2=root2;
        while((curr1!=nullptr || !s1.empty()) && (curr2!=nullptr || !s2.empty())){
            while(curr1){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            while(curr2){
                s2.push(curr2);
                curr2=curr2->left;
            }
            if(!s1.empty())curr1 = s1.top();
            //cout<<curr1->val<<' '<<s1.size()<<endl;
            if(!s2.empty())curr2 = s2.top();
            //cout<<curr1->val<<' '<<curr2->val<<endl;
            if(curr1->val<curr2->val){
                s1.pop();
                ans.push_back(curr1->val);
                curr1=curr1->right;
                curr2=nullptr;
            }
            else{
                s2.pop();
                ans.push_back(curr2->val);
                curr2=curr2->right;
                curr1=nullptr;
            }
        }
        while(curr1!=nullptr || !s1.empty()){
            while(curr1){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            curr1=s1.top();
            s1.pop();
            ans.push_back(curr1->val);
            curr1=curr1->right;
        }
        while(curr2!=nullptr || !s2.empty()){
            while(curr2){
                s2.push(curr2);
                curr2 = curr2->left;
            }
            curr2=s2.top();
            s2.pop();
            ans.push_back(curr2->val);
            curr2=curr2->right;
        }
        return ans;
    }
};