class Solution {
public:
    string longestPalindrome(string s) {
        // choose char and check if it is a middle for each palindrome string
        
        string ans;
        int max_size=0;
        
        for(int i=0;i<s.size();i++){
            int st=i,e=i;
            // <-----b-----> , for odd length
            while(st>=0 && e<s.size() && s[st]==s[e]){
                if(e-st+1>max_size){
                    ans=s.substr(st,e-st+1);
                    max_size=e-st+1;
                }
                st--;
                e++;
            }
            //even length
            st=i,e=i+1;
            while(st>=0 && e<=s.size() && s[st]==s[e]){
                if(e-st+1>max_size){
                    ans=s.substr(st,e-st+1);
                    max_size = e-st+1;
                }
                st--;
                e++;
            }
        }
        
        return ans;
    }
};