class Solution {
    
int fun(int ind,vector<int> &nums,vector<int> dp){
    if(ind==0){
        return nums[0];
    }
    if(dp[ind]!=-1) return dp[ind];
    
    int decide_to_rob = nums[ind];
    if(ind>1) decide_to_rob +=  fun(ind-2,nums,dp);
    int decide_not_to_rob = 0 + fun(ind-1,nums,dp);
    
    return dp[ind] = max(decide_to_rob,decide_not_to_rob);
}
public:
    int rob(vector<int>& nums) {
        
        
        //base
        int prev=nums[0];
        int prev2 = 0;
        //0->n-1
        for(int ind = 1;ind<nums.size();ind++){
            int decide_to_rob = nums[ind];
            if(ind>1) decide_to_rob +=  prev2;
            int decide_not_to_rob = 0 + prev;

            int curr = max(decide_to_rob,decide_not_to_rob);
            
            prev2=prev;
            prev = curr;
        }
        
        return prev;
    }
};