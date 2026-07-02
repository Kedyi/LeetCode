class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word="";
        for(int i=0;i<s.size();i++){

            if(s[i]!=' '){
                word+=s[i];
                cout<<word<<endl;
            }
            else{
                //space
                if(word.size()!=0){
                    cout<<word<<endl;
                    st.push(word);
                    word="";
                }
            }
        }
        st.push(word);
        cout<<"st: "<< st.top()<<endl;

        string ans="";
        while(!st.empty()){
            if(ans.size()!=0){
                ans+=" ";
            }
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};