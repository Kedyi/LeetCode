class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            ans=max(ans,curr);
            if(curr<0){
                //it will now decrease the sum
                curr=0;
            }
        }
        return ans;
    }
};