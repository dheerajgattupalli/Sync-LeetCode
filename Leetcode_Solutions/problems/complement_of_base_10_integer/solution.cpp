class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0, i = 0;
        if(n==0)return 1;
        while(n){
            if(n%2==0)ans|=(1<<i);
            i++;
            n/=2;
        }
        return ans;
    }
};