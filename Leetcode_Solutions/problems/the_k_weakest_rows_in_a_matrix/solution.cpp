class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> sum_values(mat.size(), make_pair(0,0));
        for(int i=0;i<mat.size();i++){
            sum_values[i].second = i;
            for(int j=0;j<mat[i].size();j++){
                sum_values[i].first+=mat[i][j];
            }
        }
        sort(sum_values.begin(),sum_values.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(sum_values[i].second);
        }
        return ans;
    }
};