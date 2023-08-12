class Solution {
int rob1(vector<int> &nums){
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
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        return max(rob1(temp1),rob1(temp2));
    }
};