class Solution {
    
private:
    vector<int> merge(vector<int> nums1,vector<int> nums2){
        if(nums1.size()==0) return nums2;
        if(nums2.size()==0) return nums1;
        
        vector<int> v;
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            v.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size()){
            v.push_back(nums2[j]);
                j++;
        }
        
        return v;
    }
    
    double median(vector<int> v){
        if(v.size()==0){
            return 0;
        }
        int mid=v.size()/2;
        if(v.size()%2==0){
            return (v[mid-1]+v[mid])/2.0;
        }
        return v[mid];
    }
    
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v=merge(nums1,nums2);
        return median(v);
    }
};