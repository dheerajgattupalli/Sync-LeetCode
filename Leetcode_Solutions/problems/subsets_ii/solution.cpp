class Solution {
public:
    void get_subsets(vector<int> nums, map<vector<int>,int > &ans,int start, vector<int> curr){
        if(start>=nums.size())return;
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            if(ans.find(curr)==ans.end())ans[curr]=1;
            get_subsets(nums, ans, i+1, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>, int> set_sets;
        vector<vector<int>> ans;
        ans.push_back(vector<int> ());
        sort(nums.begin(), nums.end());
        get_subsets(nums, set_sets, 0, vector<int> ());
        for(auto it:set_sets){
            ans.push_back(it.first);
        }
        return ans;
    }
};