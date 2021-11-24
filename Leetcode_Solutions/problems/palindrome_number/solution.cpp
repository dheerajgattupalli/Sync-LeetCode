class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
        if(x<0)return false;
        while(x>0){
            s.push_back('0'+x%10);
            x/=10;
        }
        bool ans = true;
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])ans=false;
        }
        return ans;
    }
};