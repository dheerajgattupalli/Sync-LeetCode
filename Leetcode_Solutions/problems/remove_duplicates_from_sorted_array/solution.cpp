class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        if(nums.size()==0)return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[curr]){
                curr++;
                int temp = nums[curr];
                nums[curr] = nums[i];
                nums[i] = temp;
            }
        }
        return curr+1;
    }
};