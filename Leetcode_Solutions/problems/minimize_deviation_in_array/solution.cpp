class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                nums[i]*=2;
            }
        }
        priority_queue<int> pq;
        int min_val = ans;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            min_val = min(min_val,nums[i]);
        }
        while(pq.top()%2==0 && min_val<=pq.top()){
            int val = pq.top()/2;
            pq.pop();
            pq.push(val);
            min_val = min(min_val, val);
            //cout<<val<<endl;
            ans = min(ans,abs(pq.top()-min_val));
        }
        return ans;
    }
};