class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]<9){
           digits[digits.size()-1]++;
            return digits;
        }
        int i=digits.size()-1;
        while(i>=0 && digits[i]==9){
            digits[i]=0;
            i--;
        }
        if(i>=0 && digits[i]!=9){
            ++digits[i];
        }
        else{
            vector<int> arr(digits.size()+1,0);
            arr[0]=1;
            return arr;
        }
       
        
        return digits;
    }
};