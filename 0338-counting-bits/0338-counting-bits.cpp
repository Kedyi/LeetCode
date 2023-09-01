class Solution {
    
void fun(int ind, vector<int> &ans){
        int k=ind;
        while(k){
           ans[ind]+=(k%2);
            k=k/2;
        }
}
    
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            fun(i,ans);
        }
        
        return ans;
    }
};