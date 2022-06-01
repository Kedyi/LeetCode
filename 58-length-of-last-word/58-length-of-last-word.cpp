class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int check =0;
        reverse(s.begin(),s.end());
       for(int i=0;i<s.size();i++){
        if(s[i]==' ' && check == 0){
            continue;
        }
        else if(s[i]==' '&& check ==1){
            break;
        }
        else{
            check=1;
            count++;
        }
       }
        return count;
    }
    
};