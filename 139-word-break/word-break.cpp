class Solution {

bool fun(int ind, string &s, unordered_set<string> &word, vector<int> &dp){
    //base
    if(ind==s.size()){
        return true;
    }

    if(dp[ind]!=-1) return dp[ind];

    //Try all chances of word starting ind
    for(int i=ind;i<s.size();i++){

        string w = s.substr(ind,i-ind+1);

        if(word.count(w)){
            if(fun(i+1, s, word,dp)){
                return dp[ind]= true;
            }
        }
    }

    return dp[ind]= false;
}

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,false);
        int n = s.size();

        //base
        dp[n]=true;
        
        for(int ind=n;ind>=0;ind--){
            //Try all chances of word starting ind
            for(int i=ind;i<s.size();i++){

                string w = s.substr(ind,i-ind+1);

                if(word.count(w)){
                    if(dp[i+1]){
                        dp[ind]= true;
                    }
                }
            }
        }
        return dp[0];
    }
};