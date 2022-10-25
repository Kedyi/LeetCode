class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int i=0;
        for(auto& str: s){
            if(i<s.size())
          {
            nums[i]=str;
            cout << str << ' ';
            i++;
          }
        }
        return s.size();
    }
};