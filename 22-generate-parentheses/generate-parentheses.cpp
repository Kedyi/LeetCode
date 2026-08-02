class Solution {

void fun(int open, int close, string& op, vector<string>& ans){
    //base
    if(open==0 && close==0){
        ans.push_back(op);
        return;
    }
    //open
    if(open>0){
        string op1=op;
        op1=op+"(";
        fun(open-1,close+1, op1, ans);
    }

    //close
    if(close>0){
        string op1=op;
        op1=op+")";
        fun(open, close-1, op1, ans);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=0;
        string op="";
        vector<string> ans;
        fun(open, close, op, ans);

        return ans;
    }
};