class Solution {

int fun(int i, int j, string word1, string word2,vector<vector<int>> &dp){

    //word1 finished
    if(i<0){
        return j+1;
    }
    //word2 finished
    if(j<0){
        return i+1;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(word1[i]==word2[j]){
        return dp[i][j] = fun(i-1,j-1,word1,word2,dp);
    }

    //if char are different
    int insert = fun(i-1,j,word1,word2,dp);
    int delet = fun(i,j-1,word1,word2,dp);
    int replace = fun(i-1,j-1,word1,word2,dp);

    return dp[i][j]= 1+ min({
        insert,
        delet,
        replace
    });
}
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};