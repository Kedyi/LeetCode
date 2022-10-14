class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                continue;
            }
            string temp;
            while(i<s.length() && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp==""){
                continue;
            }
            else{
                st.push(temp);
            }
        }
        
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        return ans;
    }
};