class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0,curr = nums[0], prev = INT_MAX;
        bool ans = true;
        for(int i=1;i<nums.size();i++){
            //cout<<i<<' '<<j<<endl;
            if(nums[i]<curr){
                count+=1;
                if(i==1){
                    curr = nums[i];
                }
                else if(prev<=nums[i]){
                    curr=nums[i];
                }
            }
            else{
                prev = curr;  
                curr = nums[i];              
            } 
        }
        return count<=1;
    }
};