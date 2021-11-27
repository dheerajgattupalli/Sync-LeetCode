class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1), right(nums.size(),1);
        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            left[i] = left[i-1]*nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            right[i] = right[i+1]*nums[i];
        }
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            if(i>0)ans[i]*=left[i-1];
            if(i<ans.size()-1)ans[i]*=right[i+1];
        }
        return ans;
    }
};