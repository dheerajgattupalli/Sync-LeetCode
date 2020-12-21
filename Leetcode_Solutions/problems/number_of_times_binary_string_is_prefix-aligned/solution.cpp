class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0;
        vector<int> temp1(light.size(),0);
        vector<int> temp2(light.size(),0);
        long long curr_sum = 0;
        for(int i=0;i<light.size();i++){
            curr_sum+=light[i];
            long long act_sum = ((long long)(i+1)*(long long)(i+2))/2;
            if(curr_sum==act_sum)ans++;
        }
        return ans;
    }
};