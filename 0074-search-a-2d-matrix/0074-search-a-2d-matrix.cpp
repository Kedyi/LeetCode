class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};