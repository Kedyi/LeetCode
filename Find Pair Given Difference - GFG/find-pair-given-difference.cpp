// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    // int ans =0;
    // for(int i=0;i<size;i++){
    //     for(int j=1;j<size;j++){
    //         if(i!=j && ((arr[j]-arr[i]==n) || (arr[i]-arr[j]==n))){
    //             ans = 1;
    //         }
    //         else if(arr[j]-arr[i]<n){
    //             j++;
    //         }
    //         else
    //         i++;
    //     }
    // }
    
    // return ans;
    
    
    
    
    // int i = 0;
    // int j = 1;
 
    // // Search for a pair
    // sort(arr,arr+size);
    // while (i < size && j < size)
    // {
    //     if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
    //     {
            
    //         return true;
    //     }
    //     else if (arr[j]-arr[i] < n)
    //         j++;
    //     else
    //         i++;
    // }
    
    // return -1;
    
    
    
    unordered_map<int, int> mpp;
    for(int i=0;i<size;i++){
        mpp[arr[i]]++;
        if(n==0 && mpp[arr[i]]>1){
            return 1;
        }
        
    }
    
    for(int i=0;i<size;i++){
        if(n==0){
            return 0;
        }
        if(mpp[arr[i]-n] || mpp[arr[i]+n])
          return 1;
    }
    
    return 0;
    
}