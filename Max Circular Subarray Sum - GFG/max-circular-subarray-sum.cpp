// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        int total=0;
        int maxm=INT_MIN;
        int min=INT_MAX;
        int currmax=0;
        int currmin=0;
       for(int i=0;i<num;i++){
           total+= arr[i];
           currmax+= arr[i];
           if(maxm<currmax){
               maxm=currmax;  //73 81
           }
           if(currmax<0){
               currmax=0;
           }
           currmin+= arr[i];
           if(min>currmin){
               min=currmin;  //73 81
           }
           if(currmin>0){
               currmin=0;
           }
       }
       //max = 81
       if(total == min){
           return maxm;
       }
       int curr1 = max(maxm,(total-min));
    //   curr1 = curr1*(-1);
       
       return curr1;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends