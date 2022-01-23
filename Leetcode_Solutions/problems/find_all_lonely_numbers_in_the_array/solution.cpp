class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        vector<int> ans;
        for(auto x:hash){
            if(x.second==1){
                if(hash.find(x.first-1)==hash.end() && hash.find(x.first+1)==hash.end()){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};