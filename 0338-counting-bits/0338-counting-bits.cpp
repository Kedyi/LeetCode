class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            vector<int> curr;
            int k=i;
            while(k){
               curr.push_back(k%2);
                k=k/2;
            }
            for(int j=0;j<curr.size();j++){
                ans[i]+=curr[j];
            }
        }
        
        return ans;
    }
};