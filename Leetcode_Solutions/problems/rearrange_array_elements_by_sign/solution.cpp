class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0,k=0,j=1;i<n;i++){
            if(nums[i]>0){
                ans[k]=nums[i];
                k+=2;
            }
            else{
                ans[j]=nums[i];
                j+=2;
            }
        }
        return ans;
    }
};