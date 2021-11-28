class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_idx=0,max_idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[min_idx]>nums[i])min_idx=i;
            if(nums[max_idx]<nums[i])max_idx=i;
        }
        cout<<"start"<<' '<<min_idx<<' '<<max_idx<<endl;
        cout<<"end"<<' '<<nums.size()-1-min_idx<<' '<<nums.size()-1-max_idx<<endl;
        int n = nums.size();
        int ans = max(min_idx,max_idx)+1;
        ans = min(ans, max(n-1-min_idx,n-1-max_idx)+1);
        ans = min(ans, n-1-min_idx+max_idx+2);
        ans = min(ans, n-1-max_idx+min_idx+2);
        /*
        if(min_idx<nums.size()-1-min_idx && max_idx<nums.size()-1-max_idx){
            ans = max(min_idx,max_idx)+1;
        }
        else if(min_idx<nums.size()-1-min_idx && max_idx>nums.size()-1-max_idx){
            max_idx = nums.size()-1-max_idx;
            ans = min_idx+max_idx+2;
        }
        else if(min_idx>nums.size()-1-min_idx && max_idx<nums.size()-1-max_idx){
            min_idx = nums.size()-1-min_idx;
            ans = min_idx+max_idx+2;
        }
        else{
            min_idx = nums.size()-1-min_idx;
            max_idx = nums.size()-1-max_idx;
            ans = max(min_idx,max_idx)+1;
        }
        */
        return ans;
    }
};