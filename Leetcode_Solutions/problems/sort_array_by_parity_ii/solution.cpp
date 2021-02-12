class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans(A.size(),0);        
        int odd = 1,even=0;
        for(int i=0;i<A.size();i++){
            if(A[i]%2){
                ans[odd] = A[i];
                odd+=2;
            }
            else{
                ans[even]=A[i];
                even+=2;
            } 
        }
        return ans;
    }
};