class Solution {
public:
    string removeKdigits(string num, int k) {
        string curr = num;
        for(int i=0;i<k;i++){
            int val = -1;
            for(int j=i+1;j<curr.size();j++){
                if(curr[j]<curr[j-1]){
                    val = j-1;
                    break;
                }
            }
            if(val==-1)val=curr.size()-1;
            for(int j=val;j>i;j--){
                curr[j]=curr[j-1];
            }
        }
        int start = 0;
        while(start<k || curr[start]=='0'){
            start++;
            if(curr.size()==start)break;
        }
        if(start==curr.size())return "0";
        return curr.substr(start);
    }
};