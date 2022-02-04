class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        // vector<int> left(n,0);
        //left[0] = nums[0]==1?1:-1;
        int ans = 0,sum=0;
        //for(int i=1;i<n;i++){
         //   left[i] = left[i-1]+(nums[i]==0?-1:1);
        //}
        unordered_map<int, int> hash;
        for(int i=0;i<n;i++){
            //cout<<left[i]<<endl;
            sum+=nums[i]==1?1:-1;
            if(sum==0){
                ans = max(ans, i+1);
            }
            if(hash.find(sum)!=hash.end()){
                //cout<<left[i]<<' '<<hash[left[i]]<<endl;
                ans = max(ans, i-hash[sum]);
            }
            else{
                hash[sum] = i;
            }
        }
        //cout<<endl;
        return ans;
    }
};