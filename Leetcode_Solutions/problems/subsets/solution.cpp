class Solution {
public:
    void recFun(vector<int> &nums, vector<vector<int>> &ans, int start, vector<int> &curr){
        if(start>=nums.size())return;
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            ans.push_back(curr);
            recFun(nums, ans, i+1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        ans.push_back(curr);
        recFun(nums, ans, 0, curr);
        return ans;
    }
};