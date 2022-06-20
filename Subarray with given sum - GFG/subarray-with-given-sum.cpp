// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        // int left=1;
        // int right=1;
        // long long currsum=0;
        // while(right!=n){
        //   if(currsum==s){
        //       return {left,right};
        //   }
        //   else if(currsum>s){
        //       currsum = currsum-arr[left];
        //       left = left+1;
        //   }
        //   else{
               
        //       currsum += arr[right];
        //       right++;
        //   }
           
        // }
        // return {-1,-1};
        int it=0;
      int sum=0;
      for(int i=0;i<n;i++){
         sum += arr[i];
         while(sum>s){
              sum -= arr[it];
              it++;
          }
         if(sum==s){
              return {it+1, i+1};
          }
      }
      return {-1};
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends