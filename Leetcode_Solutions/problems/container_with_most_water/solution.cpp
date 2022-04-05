class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0,j=height.size()-1;j>i;){
            ans=max(ans,min(height[i],height[j])*(j-i));
            if(height[j]>height[i])i++;
            else j--;
        }
        return ans;
    }
};