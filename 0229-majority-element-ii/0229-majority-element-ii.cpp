class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        map<int,int> mpp;
        for(int i=0;i<n;i++){
           if(mpp.find(nums[i])==mpp.end()){
               mpp.insert({nums[i],1});
           }
           else{
               int z = mpp[nums[i]];
               cout<<z<<endl;
               mpp[nums[i]]= ++z;
           }
        }
         for (auto it = mpp.begin();it != mpp.end(); ++it){
        //cout << it->first << " = " << it->second << '\n';
         if(it->second >n/3){
             v.push_back(it->first);
         }
         }
        return v;
    }
};