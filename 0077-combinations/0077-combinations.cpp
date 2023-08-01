class Solution {
public:
    vector<vector<int>> arr;
    vector<int> nums;
    void backtrack(vector<int>& nums, vector<vector<int>>& arr,int n, int k, int pos, int cur){
        if(pos == k){ 
            arr.push_back(nums);
            return;
        }
        for(int i=cur; i<=n-k+pos+1; i++){ 
            nums[pos] = i;
            backtrack(nums, arr, n, k, pos+1, i+1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        nums = vector<int>(k);
        backtrack(nums, arr, n, k, 0, 1);
        return arr; 
    }
};