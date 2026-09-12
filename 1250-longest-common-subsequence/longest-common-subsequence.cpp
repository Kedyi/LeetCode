class Solution {

int fun(int i, int j, string text1, string text2, vector<vector<int>> &dp){
    if(i<0 || j<0){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    //if both index have same element
    if(text1[i]==text2[j]){
        return dp[i][j] = 1+fun(i-1, j-1, text1, text2,dp);
    }
    //string1 move, not taking anything now
    int one = 0 + fun(i-1,j,text1,text2,dp);

    //string2 move, not taking anything now
    int two = 0 + fun(i, j-1,text1, text2,dp);

    return dp[i][j]=max(one, two);
}

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                //if both index have same element
                if(text1[i]==text2[j]){
                    dp[i][j]=1;
                    if(i>0&&j>0)
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                //string1 move, not taking anything now
                int one = 0;
                if(i>0)
                one = 0 + dp[i-1][j];

                //string2 move, not taking anything now
                int two = 0;
                if(j>0)
                two = 0 + dp[i][j-1];

                dp[i][j]=max(one, two);
                }
            }
        }

        return dp[n-1][m-1];
    }
};