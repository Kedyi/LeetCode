// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& matrix, int n) {
	   //  for(int i=0;i<n;i++){
	   //      for(int j=i;j<n;j++){
	   //          int temp=arr[i][j];
	   //          arr[i][j]=arr[j][i];
	   //          arr[j][i]=temp;
	   //      }
	   //      for(int i=0;i<n;i++){
	   //          int li=0;
	   //          int ri=n-1;
	   //          while(li<ri){
	   //          int temp=arr[li][i];
	   //          arr[li][i]=arr[ri][i];
	   //          arr[ri][i]=temp;
	             
	   //          li++;
	   //          ri--;
	   //      }
	   //      }
	   //  }

    for(int i=0; i<matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j= i+1; j< matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends