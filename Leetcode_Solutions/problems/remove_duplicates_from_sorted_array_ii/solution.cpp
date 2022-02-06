class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0,curr=0,good=1,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                count=0;
            }
            if(count<2){
                nums[good++]=nums[i];
            }
        }
        return good;
    }
};