class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<bool> p(1001,true);
        int i = 2,j;
        for(i = 2; i <= 1000; i++){
            if(p[i]){
                for(j = i*i; j <= 1000; j+=i){
                    p[j] = false;
                }
            }
        }
        unordered_set<int> a,b;
        for(i  = 2; i < 1000; i++){
            if(p[i]){
                b.insert(i);
            }
        }
        for(auto &i: b){
            for(auto &j: nums){
                if(j%i==0){
                    a.insert(i);
                    break;
                }
            }
            
        }
        return a.size();
    }
};