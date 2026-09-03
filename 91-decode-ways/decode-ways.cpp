class Solution {

int fun(int ind, string& s, vector<int>& dp){

    int n = s.size();
    if(ind==n){
        //successfully decoded
        return 1;
    }

    //cannot decode if last==0
    if(s[ind]=='0'){
        return 0;
    }

    if(dp[ind]!=-1) return dp[ind];

    //Take one digit
    int one = fun(ind+1,s,dp);


    //Take two digit
    //condition: 10<=num<=26
    int two=0;

    if(ind+1<n){
        int num = (s[ind]-'0')*10 + (s[ind+1]-'0');

        if(num>=10 && num<=26){
            two = fun(ind+2,s,dp);
        }
    }

    return dp[ind] = one+two;

}
public:
    int numDecodings(string s) {

        vector<int> dp(s.size(),-1);
        return fun(0,s, dp);
    }
};