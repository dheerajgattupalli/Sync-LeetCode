class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, curr=0;
        for(int i=0;i<nums.size();i++){
            if(curr+nums[i]>ans){
                ans = curr+nums[i];
            }
            curr += nums[i];
            if(curr<0)curr=0;
        }
        return ans;
    }
};