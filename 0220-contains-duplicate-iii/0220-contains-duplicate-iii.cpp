class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
        multiset<int> mp;     
        
		int i=0, j=0;
        while(j<n)
        {
            auto up = mp.upper_bound(nums[j]);
           if((up != mp.end() and *up-nums[j] <= valueDiff) || (up != mp.begin() and nums[j] - *(--up) <= valueDiff))
                return true;
            mp.insert(nums[j]);
            
            if(mp.size() == indexDiff+1)
            {
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};