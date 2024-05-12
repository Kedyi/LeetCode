class Solution {
public:
    int findPermutationDifference(string s, string t) {
        /*
        1. s[i] check in t[j] -> abs(i-j): TC:O(n^2) SC:O(1)
        2. hashmap - > store index with element-> find the element ->take index and abs(i-j): TC:O(2n), SC: O(2n)
        */
        //1
        int ans=0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(s[i]==t[j]){
                   ans += abs(i-j);
               }
           } 
        }
        return ans;
    }
};