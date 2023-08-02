class Solution {
public:
    void fun(int id,vector<int>&nums,vector<vector<int>>&res){
        if(id==nums.size()){
            res.push_back(nums);
            return;
        } 
        for(int i=id;i<nums.size();i++){
            swap(nums[id],nums[i]);
            fun(id+1,nums,res);
            swap(nums[id],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        fun(0,nums,res);
        return res;
    }
};