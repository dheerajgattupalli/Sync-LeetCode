class Solution {
public:
    //int gcd(int a,int b){
    //   if(a<=1)return b;
    //    return gcd(a%b, a);
    //}
    long long lcm(long long a,long long b){
        return a/gcd(a,b)*b;
    }
    long long fn(long long a, long long b, long long val){
        return val/a + val/b - val/lcm(a,b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long ans = 0;
        int mod = 1000000007;
        int temp = a;
        a = min(a,b);
        b = max(temp,b);
        //cout<<a<<' '<<b<<endl;
        long long low=0,high=(long long)n*(long long)a,mid;
        while(low<high){
            mid = low+(high-low)/2;
            //cout<<low<<' '<<mid<<' '<<high<<endl;
            if(fn(a,b,mid)<n)
                low=mid+1;
            else high=mid;
        }
        return low%mod;
    }
};