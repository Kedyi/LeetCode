class Solution {
public:
    int maxCoins(vector<int>& piles) {
        //8 7 4 2 2 1
        vector<int> temp;
        sort(piles.begin(),piles.end(),greater<>());
        int i=0;
        int j=piles.size()-1;
        while(i<piles.size() && j>=0 && i<j){
            temp.push_back(piles[i]);
            i++;
            temp.push_back(piles[i]);
            i++;
            temp.push_back(piles[j]);
            j--;
        }
        
        // for(int k=0;k<temp.size();k++){
        //     cout<<temp[k];
        // }
        
       // 8 7 1 4 2 2
        int ans=0;  
        for(int i=1;i<temp.size();i+=3){
            ans+=temp[i];
        }
        return ans;
    }
};