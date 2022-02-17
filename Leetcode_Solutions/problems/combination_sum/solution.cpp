class Solution {
public:
    void recFn(vector<int> &nums, vector<int> &curr,int currsum, int target,
              vector<vector<int>> &ans, int start){
        if(start>=nums.size() || currsum>target)return;
        if(target==currsum)ans.push_back(curr);
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            recFn(nums,curr,currsum+nums[i],target,ans,i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        recFn(candidates,curr,0,target,ans,0);
        return ans;
    }
};