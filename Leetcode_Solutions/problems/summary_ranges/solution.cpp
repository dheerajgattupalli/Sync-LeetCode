class Solution {
public:
    string getStr(long long int n){
        bool neg=false;
        if(n<0){
            neg=true;
            n*=-1;
        }
        string s;
        if(n==0)s.push_back('0');
        while(n>0){
            s.push_back(n%10+'0');
            n/=10;
        }
        if(neg)s.push_back('-');
        reverse(s.begin(),s.end());
        return s;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)return ans;
        int n = nums.size(),start = nums[0],prev=nums[0];
        string temp;
        for(int i=1;i<n+1;i++){
            if(i<n && nums[i]==prev+1){
                prev = nums[i];
            }
            else{
                temp = getStr(start);
                //cout<<temp<<endl;
                if(prev==start)ans.push_back(temp);
                else{
                    temp+='-';
                    temp+='>';
                    temp+=getStr(prev);
                    ans.push_back(temp);
                }
                if(i<n){
                    prev = nums[i];
                    start = nums[i];
                }
            }
        }
        return ans;
    }
};