class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int total=0;
        int maxm=INT_MIN;
        int min=INT_MAX;
        int currmax=0;
        int currmin=0;
       for(int i=0;i<arr.size();i++){
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