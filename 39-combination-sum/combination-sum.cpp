class Solution {

void fun(int ind, vector<int>& candidates, int target, vector<int>& ans, vector<vector<int>>& res){
    //got integers
    if(target==0){
        res.push_back(ans);
        return;
    }
    //target!=0 and ind finished
    if(ind>=candidates.size()) return;

    //take only if target>=item
    if(target>=candidates[ind]){
        ans.push_back(candidates[ind]);
        fun(ind, candidates, target-candidates[ind], ans, res);
        //back track for not taking, pop should only happen if pushed
        ans.pop_back();
    }

    //not take
    fun(ind+1, candidates, target, ans, res);

}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        fun(0, candidates, target, ans, res);

        return res;
    }
};