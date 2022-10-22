class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=1;
        int n =nums.size();
        int mx = nums[0];
        for(int i=0;i<n-1;i++){ 
            cout<<nums[i]<<" ";
            while(i<n-1 && nums[i]==nums[i+1] ){
                c++;
                i++;
            }
                if(c>n/2){
                    mx=nums[i];
                    c=0;
                }
            
        }
        return mx;
    }
};