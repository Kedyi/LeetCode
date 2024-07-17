class Solution {
    

    
public:
    string countAndSay(int n) {
        
        //base case
        if(n==1) return "1";
        
        string temp = countAndSay(n-1);
        
        string ans="";
        for(int i=0;i<temp.size();i++){
            int cnt=1;
            int t = temp[i];
            while(i<temp.size() && temp[i]==temp[i+1]){
                cnt++;
                i++;
            }
            ans+=to_string(cnt);
            ans+=t;
        }
        
        return ans;
        
    }
};