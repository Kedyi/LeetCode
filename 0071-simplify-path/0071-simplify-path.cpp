class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stack<string> st;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')
                continue;
            string temp;
            while(i<path.length() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!st.empty())
                st.pop();
            }
            else
            st.push(temp);
        }
        
        while(!st.empty()){
            s = "/"+ st.top()+s;
            st.pop();
        }
        
       if(s==""){
           return "/";
       }
        
        return s;
    }
};