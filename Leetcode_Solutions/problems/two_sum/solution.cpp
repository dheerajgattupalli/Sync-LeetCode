class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash; 
        for(int i=0;i<n;i++){
            hash[nums[i]] = i;
        }
        vector<int> ans;
        int second_idx;
        for(int i=0;i<n;i++){
            if(hash.find(target-nums[i])!=hash.end())
            {
                second_idx = hash[target-nums[i]];
                if(second_idx==i)continue;
                ans.push_back(i);
                ans.push_back(second_idx);
                break;
            }
        }
        return ans;
    }
};