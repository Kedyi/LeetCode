class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        int n=nums.size();
        for(i=0;i<n;i++){
           if(nums[i]!=i){
               return i;
           } 
        }
        return i;
    }
};