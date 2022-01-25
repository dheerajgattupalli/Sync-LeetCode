class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)return false;
        bool greater = true,ans=true;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1])return false;
            if(greater){
                if(i>1 && arr[i]<arr[i-1])greater=false;
                else if(arr[i]<=arr[i-1])return false;
            }
            else{
                if(arr[i]>=arr[i-1])return false;
            }
        }
        if(greater)return false;
        return true;
    }
};