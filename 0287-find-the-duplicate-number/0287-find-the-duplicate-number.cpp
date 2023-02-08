class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return nums[i];
            }
            mpp.insert(make_pair(nums[i],1));
      }
        for(auto x: mpp){
            cout<< x.first<< " ";
        }
        return 0;
    }
};