class Solution {
    
 int rob1(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        //base case 0
        
    for(int ind=1;ind<nums.size();ind++){
        int nottake = 0 + prev;
        int take = nums[ind];
        if(ind>1) take += prev2;

        int curr = max(take,nottake); 

        prev2=prev;
        prev=curr;
    }
       return prev;
}
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<nums.size();i++){
            
            if(i!=0)  temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        
        return max(rob1(temp1),rob1(temp2));
    }
};