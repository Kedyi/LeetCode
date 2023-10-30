class Solution {
    
private:
    string check(string haystack, int ind, string needle){
        string ans;
        int n = needle.size();
        //cout<<ind<<" "<<n<<" ";
        for(int i=ind;i<ind+n;i++){
            ans+=haystack[i];
        }
        
        //cout<<ans<<endl;
        return ans;
    }
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        if(needle==haystack){
           return 0; 
        }
        if(n>haystack.size()) return -1;
        for(int i=0;i<=haystack.size()-n;i++){
            string ans = check(haystack, i, needle);
            if(ans==needle) return i;
        }
        
        return -1;
    }
};