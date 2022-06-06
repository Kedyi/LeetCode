class Solution {
public:
    string convert(string s, int numRows) {
      vector<string> n(numRows) ;
        
        if(numRows==1)
            return s;
        
      for(int i=0;i<s.length();i++)
      {
          if((i/(numRows-1))&1)
              n[numRows-(i%(numRows-1))-1]+=s[i];
          else
              n[i%(numRows-1)]+=s[i];
      }
        string res;
        for(int i=0;i<numRows;i++)
            res+=n[i];
        return res;
    }
};