class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> counts;
        for(int i=0;i<nums.size();i++){
            counts[nums[i]]+=1;
        }
        int ans = 0;
        for(auto val:counts){
            //cout<<val.first<<' '<<val.second<<endl;
            int curr = val.second,curr1,curr2;
            if(counts.find(val.first-1)!=counts.end()){
                curr1 = curr+counts[val.first-1];
            }
            if(counts.find(val.first+1)!=counts.end()){
                curr2 = curr+counts[val.first+1];
            }
            curr = max(curr1,curr2);
            ans = max(curr, ans);
        }
        return ans;
    }
};