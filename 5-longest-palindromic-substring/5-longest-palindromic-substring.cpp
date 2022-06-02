
class Solution {
public:
    string longestPalindrome(string st) {
        
//         string ans ="";
//         int max_length = 0;
//         for(int i=0;i<st.size();++i){
//             int s=i, e=i;
//             while(st[s]==st[e] && s>=0 && e <st.size()){
//                 if(e-s+1>max_length){
//                     ans = st.substr(s,e-s+1);
//                        max_length = e-s+1;
//                 }
//                 s--;
//                 e++;
                
//             }
//             s=i, e=i+1;
//              while(st[s]==st[e] && s>=0 && e <st.size()){
//                 if(e-s+1>max_length){
//                     ans = st.substr(s,e-s+1);
//                        max_length = e-s+1;
//                 }
//                 s--;
//                 e++;
                
//             }
//         }
//         return ans;
//     }
        
        string ans = "";
        int max_length = 0;
        for(int i=0;i<st.size();i++){
            int s=i,e=i;
            
            //odd
            while(s>=0 && e<st.size()&& st[s]==st[e]){
                if(e-s+1>max_length){
                    ans = st.substr(s,e-s+1);
                    max_length = e-s+1;
                }
                s--;
                e++;
            }
            
            s=i,e=i+1;
             //even
            while(s>=0 && e<st.size()&& st[s]==st[e]){
                if(e-s+1>max_length){
                    ans = st.substr(s,e-s+1);
                    max_length = e-s+1;
                }
                s--;
                e++;
            }
        }
        return ans;
    }
        
        
        
};