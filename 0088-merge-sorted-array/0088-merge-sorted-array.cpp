class Solution {
public:
    
    void merge_arrays(vector<int>& nums1, int m, int num){
        int top_element=0;
        if(!nums1.empty()){
            top_element = nums1.back();
            cout<<top_element;
        }
        if(!nums1.empty() && top_element>num ){
            nums1.pop_back();
            merge_arrays(nums1,m,num);
            nums1.push_back(top_element);
        }
        if(nums1.empty() || nums1.back()<=num)
        nums1.push_back(num);
        return;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=n;
        while(k){
            nums1.pop_back();
            k--;
        }
        
        if(nums1.size()==0){
            nums1=nums2;
            return;
        }
        if(n==0){
            return;
        }
        
        for(int i=0;i<n;i++){
            merge_arrays(nums1,nums1.size(),nums2[i]);
        }
        
    }
};