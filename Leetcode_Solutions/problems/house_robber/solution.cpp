class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(i>0)
                dp[i+1] = max(dp[i],dp[i-1]+nums[i]);
            else
                dp[i+1] = nums[i];
        }
        return dp[nums.size()];
    }
};