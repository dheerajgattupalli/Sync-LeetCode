class Solution {
public:
    int getPrimesum(int n){
        int sum=0;
        while(n>0 && n%2==0){
            n/=2;
            sum+=2;
            //cout<<"2 "<<n<<endl;
        }
        for(int i=3;i<=sqrt(n);i+=2){
            while(n>0 && n%i==0){
                sum+=i;
                n/=i;
                //cout<<i<<' '<<n<<endl;
            }
        }
        if(n>1)sum+=n;
        cout<<"final "<<n<<endl;
        return sum;
    }
    int smallestValue(int n) {
        int ans = getPrimesum(n);
        if(ans==n)return n;
        return smallestValue(ans);
    }
};