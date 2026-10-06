class Solution {
int fun(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){

    //base case: word1 is finished
    if(i<0){
        return j+1;
    }

    //if word2 is finished
    if(j<0){
        return i+1;
    }

    //Character same
    if(word1[i]==word2[j]){
        return dp[i][j] = fun(i-1,j-1,word1,word2,dp);
    }

    //Character are different
    int deleteChar = fun(i-1,j,word1, word2,dp);
    int insertChar = fun(i, j-1, word1, word2,dp);
    int replaceChar = fun(i-1,j-1,word1,word2,dp);

    return dp[i][j] = 1+ min({deleteChar,insertChar,replaceChar});
}
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m= word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //n+1 and m+1 to handle base case

        //base case: word1 is empty->insert j char
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }

        //word2 is empty->delete i character
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //Character same
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                
                //Character are different
                int deleteChar = dp[i-1][j];
                int insertChar = dp[i][j-1];
                int replaceChar = dp[i-1][j-1];

                dp[i][j] = 1+ min({deleteChar,insertChar,replaceChar});
                }
            }
        }


        return dp[word1.size()][word2.size()];       
    }
};