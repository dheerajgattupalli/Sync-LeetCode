class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                vector<int> ans = {i, hash[target-nums[i]]};
                return ans;
            }
            hash[nums[i]] = i;
        }
        return vector<int> ();
    }
};