class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int alice=capacityA,bob=capacityB,n=plants.size();
        int ans =0;
        for(int i=0;i<n/2;i++){
            if(plants[i]>alice){
                ans++;
                alice=capacityA-plants[i];
            }
            else alice-=plants[i];
            if(plants[n-i-1]>bob){
                ans++;
                bob=capacityB-plants[n-i-1];
            }
            else bob-=plants[n-i-1];
        }
        //cout<<alice<<' '<<bob<<' '<<ans<<endl;
        if(n%2){
            if(alice>=bob){
                if(alice<plants[n/2])ans++;
            }
            else{
                if(bob<plants[n/2])ans++;
            }
        }
        return ans;
    }
};