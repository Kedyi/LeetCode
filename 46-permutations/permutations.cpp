class Solution {
void fun(int ind, vector<int>& nums, vector<vector<int>>& res){
    if(ind>=nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[ind], nums[i]);
        fun(ind+1, nums, res);
        swap(nums[ind], nums[i]);
    }

}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        fun(0, nums, res);

        return res;
    }
};