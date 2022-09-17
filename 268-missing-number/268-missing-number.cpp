class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i,j;
        for(i=0,j=0;i<nums[n],j<n;i++,j++){
            if(i!=nums[j]){
                return i;
            }
        }
        return i;
    }
};