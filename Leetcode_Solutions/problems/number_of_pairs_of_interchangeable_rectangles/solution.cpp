class Solution {
public:
    long long int nc2(long long int n){
        return n*(n-1)/2;
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long int> hash;
        for(int i=0;i<rectangles.size();i++){
            hash[(double)rectangles[i][1]/(double)rectangles[i][0]]++;
        }
        long long int ans = 0;
        for(auto it:hash){
            ans += nc2(it.second);
            //cout<<it.second<<' '<< nc2(it.second)<<endl;
        }
        return ans;
    }
};