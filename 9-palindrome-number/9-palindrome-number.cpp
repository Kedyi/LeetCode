class Solution {
public:
    //x=121
    bool isPalindrome(int x){
        long int num=0;//0
        long int z=x; //121
      while(z>0){
          num = (num*10)+(z%10);
          z=z/10;
      }
        if(num==x){
            return true;
        }
        
        return false;
    }
};