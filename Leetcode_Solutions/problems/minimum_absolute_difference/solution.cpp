class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_=INT_MAX;
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++){
            min_ = min(min_,abs(arr[i]-arr[i+1]));
        }
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(abs(arr[j]-arr[i])==min_){
                    vector<int> temp{arr[i],arr[j]};
                    ans.push_back(temp);
                }
                if(abs(arr[j]-arr[i])>min_)break;
            }
        }
        return ans;
    }
};