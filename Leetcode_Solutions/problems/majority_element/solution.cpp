class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(ans==nums[i])count++;
            else count--;
            if(count<0){
                count=0;
                ans=nums[i];
            }
        }
        return ans;
    }
};