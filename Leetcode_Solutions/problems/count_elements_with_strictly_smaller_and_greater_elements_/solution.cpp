class Solution {
public:
    int countElements(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans = n-2,i=1, j = n-2;
        while(i<n){
            if(nums[i]==nums[i-1])ans--;
            else break;
            i++;
        }
        while(j>=0){
            if(nums[j]==nums[j+1])ans--;
            else break;
            j--;
        }
        return max(ans,0);
    }
};