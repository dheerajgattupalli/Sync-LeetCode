class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        map<pair<int,int>,int> ans;
        //cout<<"==============="<<endl;
        //sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i]-k)!=hash.end()){
                ans[make_pair(nums[i]-k, nums[i])]++;
            //    cout<<nums[i]-k<<' '<<nums[i]<<endl;
            }
            if(hash.find(nums[i]+k)!=hash.end()){
                ans[make_pair(nums[i],nums[i]+k)]++;
                //cout<<nums[i]+k<<' '<<nums[i]<<endl;
            }
            hash[nums[i]]++;
        }
        return ans.size();
    }
};