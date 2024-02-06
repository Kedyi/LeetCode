class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        if((s.size())%2!=0) return false;
        
        for(int i=0;i<s.size();i++){
            
            char ch = s[i];
            
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            
            else{
                if(!st.empty()){
                    
                    if((ch==')' && st.top()=='(') || (ch=='}' && st.top()=='{') || (ch==']' && st.top()=='[')){
                        st.pop();
                    }
                else return false;
                }
                
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};