class Solution {

private:

    bool fun(int ind, string& s, unordered_set<string>& st, vector<int> &dp){
        if(ind==s.size()){
            return true;
        }

        if(dp[ind]!=-1) return dp[ind];

        //Try every possible word starting at i
        for(int i=ind;i<s.size();i++){
            string word = s.substr(ind, i-ind+1);

            //If this string is present in dictionary
            if(st.count(word)){
                if(fun(i+1, s, st, dp)){
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(),-1);
        return fun(0,s,st, dp);
    }
};