// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size() == 0){
            return mergedIntervals;
        }
         //sort the lists of list
         sort(intervals.begin(),intervals.end());
        //create a temp vector to store present intervals
        vector<int> tempIntervals = intervals[0];
        //start a loop
        for(auto i : intervals){
             //if(interval[0]<= intervalpresent[1])
             if(i[0]<=tempIntervals[1]){
        //yes => intervalpresent[1] = max(interval[1],intervalpresent[1])
              tempIntervals[1]= max(i[1],tempIntervals[1]);
             }
             else{
        //mergeinterval pushback the intervalpresent
               mergedIntervals.push_back(tempIntervals);
              //and interval present = interval[i]
               tempIntervals = i;
             }
        }
       
        //at last push all in mergeinterval
        mergedIntervals.push_back(tempIntervals);
        //return mergeinterval
        return mergedIntervals;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends