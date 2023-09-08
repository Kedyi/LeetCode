class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> prev;
        for(int i=0;i<numRows;i++){
            vector<int> curr;
            curr.push_back(1);
            if(i>1){
                for(int j=0;j<prev.size()-1;j++){
                    curr.push_back(prev[j]+prev[j+1]);
                }
            }
            if(i>0){
               //case i=1...i.e. push 1,1
                curr.push_back(1);
            }
          v.push_back(curr);
          prev = curr;
        }
        return v;
    }
};