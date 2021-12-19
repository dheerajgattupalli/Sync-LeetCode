class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i])return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            if(isPalindrome(words[i]))return words[i];
        }
        return "";
    }
};