class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        if(intervals.size()==0){
            return mergeIntervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> presentInterval = intervals[0];
        for(auto i : intervals){
            if(i[0]<=presentInterval[1]){
                presentInterval[1]= max(i[1],presentInterval[1]);
            }
            else{
                mergeIntervals.push_back(presentInterval);
                presentInterval = i;
            }
            
        }
        mergeIntervals.push_back(presentInterval);
        return mergeIntervals;
        
    }
};