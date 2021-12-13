class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int n = s.size();
        if(n==0)return ans;
        int count = 1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])count++;
            else count=1;
            ans = max(ans,count);
        }
        ans = max(ans,count);
        return ans;
    }
};