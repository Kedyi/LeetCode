class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        //2 element
        //arr[i]-arr[i-1] is same
        //for l.size() (find the start and end index -> sort it -> check the difference)
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            //3 times run
            int start = l[i];
            int end = r[i];
            vector<int> temp;
            for(int j=start;j<=end;j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            bool answer=true;
            int check=temp[1]-temp[0];
            for(int k=2;k<temp.size();k++){
                if(temp[k]-temp[k-1]!=check){
                    answer=false;
                    break;
                }
            }
            
            ans.push_back(answer);
        }
        
        return ans;
    }
};