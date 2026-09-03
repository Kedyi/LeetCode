class Solution {

private:
    int fun(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
        
        if(ind<0){
            return 0;
        }

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

       int take = INT_MIN;
       if(prev==-1 || prev-ind>1)
       take = nums[ind] + fun(ind-1, ind, nums, dp);

       int nottake = 0 + fun(ind-1, prev, nums, dp);

       return dp[ind][prev+1] = max(take, nottake);
    }
public:
    int rob(vector<int>& nums) {

        int n= nums.size();
        if(n==1){
            return nums[0];
        }

        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n;i++){
            if(i!=0){
                temp2.push_back(nums[i]);
            }
            if(i!=n-1){
                temp1.push_back(nums[i]);
            }
        }

        vector<vector<int>> dp1(n-1,vector<int>(n,-1));
        vector<vector<int>> dp2(n-1,vector<int>(n,-1));

        return max(fun(n-2,-1,temp1, dp1),fun(n-2,-1,temp2, dp2));
    }
};