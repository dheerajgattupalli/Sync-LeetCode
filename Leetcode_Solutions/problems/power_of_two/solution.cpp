class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ones = 0;
        while(n>0){
            ones+=n%2;
            n/=2;
        }
        return ones==1;
    }
};