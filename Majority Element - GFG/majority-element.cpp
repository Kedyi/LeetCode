// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
    //   unordered_map<int, int> m;
    //     for(int i=0;i<size;i++)
    //       m[arr[i]]++;
         
    //      for(auto i: m)
    //          if(i.second > size/2)
    //           return i.first;
         
    //     return -1;
        
        
        if(size==1){
            return arr[0];
        }
        int count=1;
        sort(arr,arr+size);
        for(int i=1;i<size;i++){
            if(arr[i-1]==arr[i]){
                count++;
            }
           else{
               if(count > size / 2){
                 return arr[i-1];
               }
               count=1;

        }
        }
        if(count>size/2){
            return arr[size-1];
        }
     return -1;   
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends