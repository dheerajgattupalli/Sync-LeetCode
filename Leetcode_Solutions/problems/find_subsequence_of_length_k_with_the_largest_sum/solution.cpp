 bool compare(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
class Solution {
public:
   
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> hash;
        int n= nums.size();
        unordered_map<int,int> inds;
        for(int i=0;i<n;i++){
            if(hash.size()==k && hash.top().first<nums[i]){
                hash.pop();
            }
            if(hash.size()<k){
                hash.push(make_pair(nums[i],i));
            }
        }
        vector<pair<int,int>> ans;
        while(!hash.empty()){
            ans.push_back(hash.top());
            hash.pop();
        }
        sort(ans.begin(),ans.end(),compare);
        vector<int> final_ans;
        for(auto x:ans)final_ans.push_back(x.first);
        return final_ans;
    }
};