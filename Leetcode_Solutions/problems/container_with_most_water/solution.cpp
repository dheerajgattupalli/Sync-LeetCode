class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0, j=height.size()-1;j>i;){
            int curr = min(height[j],height[i])*(j-i);
            if(height[j]<height[i])j--;
            else i++;
            ans = max(curr,ans);
        }
        return ans;
    }
};