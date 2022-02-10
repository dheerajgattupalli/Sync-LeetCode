class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> left;
        int sum =0;
        left[sum]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(left.find(sum-k)!=left.end()){
                ans+=left[sum-k];
            }
            left[sum]++;
        }
        return ans;
    }
};