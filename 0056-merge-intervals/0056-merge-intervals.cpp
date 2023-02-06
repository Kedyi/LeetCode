class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        int len=intervals.size();
        //if only one vector
        if(len<=1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        v.push_back(intervals[0]);
        for(int i=1;i<len;i++){
            
          vector<int> temp = v.back();
          int n = intervals[i].size();
          int m = temp.size();  
            
          if(temp[m-1]>=intervals[i][0]){
              v.pop_back();
              int min_till_now = min(temp[0],intervals[i][0]);
              int max_till_now = max(temp[m-1],intervals[i][n-1]);
              temp.clear();
              temp.push_back(min_till_now);
              temp.push_back(max_till_now);
              v.push_back(temp);
          }  
          else
              v.push_back(intervals[i]);
        }
        
        for(int i=0;i<len;i++){
            for(int j=0;j<intervals[i].size();j++)
            cout<<intervals[i][j];
        }
        
        
        return v;
    }
};