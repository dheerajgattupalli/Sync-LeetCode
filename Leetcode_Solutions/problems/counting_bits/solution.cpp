class Solution {
public:
    int countBitsN(int n){
        int count=0;
        for(int i=0;i<17;i++){
            if(n&1<<i)count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countBitsN(i));
        }
        return ans;
    }
};