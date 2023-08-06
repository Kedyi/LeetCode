class Solution {
    
int fun(int start, int end, vector<int> nums, int target){
    if(start>end){
        return -1;
    }
    
    int mid = (start+end)/2;
    if(nums[mid]==target) return mid;
    int a=-1;
    if(nums[mid]>target)  
         a = fun(start, mid-1,nums,target);
    else a = fun(mid+1,end,nums,target);
    
    return a;
} 
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        return fun(start,end,nums,target);
    }
};