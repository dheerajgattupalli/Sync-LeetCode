class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        int count=0,ans=0;
        while(num>0){
            count++;
            ans+=num%10;
            num/=10;
        }
        if(count==1)return ans;
        return addDigits(ans);
    }
};