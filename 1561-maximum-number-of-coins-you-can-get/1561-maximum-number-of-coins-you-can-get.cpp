class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //8 7 4 2 2 1
        sort(piles.begin(),piles.end());
        int ans=0;
        for(int i=piles.size()/3;i<piles.size();i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};