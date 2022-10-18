class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> v;
        int mx=INT_MAX;
        for(int i=0;i<list1.size();i++){
            int curr=0;
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    curr = i+j;
                    cout<<list1[i]<< " "<< i<<" " <<j<<" "<<mx<<endl;
                    if(curr<=mx){
                        if(curr==mx){
                            v.push_back(list1[i]);
                        }
                        else{
                        mx=curr;
                        while(!v.empty())
                        v.pop_back();
                        v.push_back(list1[i]);
                        }
                    }
                }
            }
        }
        return v;
    }
};