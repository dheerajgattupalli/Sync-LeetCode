class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int r1 = 1%k,ans=1;
        if(k%2==0 || k%5==0)return -1;
        unordered_set<int> hash;
        while(r1!=0){
            if(hash.find(r1)!=hash.end())return -1;
            hash.insert(r1);
            ans++;
            r1 = (r1*10+1)%k;
        }
        return ans;
    }
};