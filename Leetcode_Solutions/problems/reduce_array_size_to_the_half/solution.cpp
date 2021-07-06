class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        vector<int> counts;
        for(auto it:hash)
            counts.push_back(it.second);
        int ans = 0,curr=0,n = arr.size();
        sort(counts.begin(),counts.end(),greater<>());
        while(curr<n/2){
            curr+=counts[ans];
            ans++;
        }
        return ans;
    }
};