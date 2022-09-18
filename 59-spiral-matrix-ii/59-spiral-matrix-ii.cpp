class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v;
        int arr[n][n];
       
        int top=0;
        int down=n-1;
        int right=n-1;
        int left=0;
        int dir=0;
        //0=left->right
        //1=top->down
        //2 = right->left
        //3= down->top
        int c=1;
    while(top<=down && right>=left){
    if(dir==0){
        for(int i=left;i<=right;i++){
            arr[top][i]=c;
            c++;
        }
        top++;
        dir=1;
    }
    else if(dir==1){
        for(int i=top;i<=down;i++){
            arr[i][right]=c;
            c++;
        }
        right--;
        dir=2;
    }
    else if(dir==2){
        for(int i=right;i>=left;i--){
            arr[down][i]=c;
            c++;
        }
        down--;
        dir=3;
    }
    else if(dir==3){
        for(int i=down;i>=top;i--){
            arr[i][left]=c;
            c++;
        }
        left++;
        dir=0;
    }
    
    else 
      break;
    }
       for(int i=0;i<n;i++){
                vector<int> v1;
           for(int j=0;j<n;j++){
               cout<<arr[i][j]<<" ";
               v1.push_back(arr[i][j]);
               
           }
           v.push_back(v1);
           cout<<endl;
       }
       return v; 
    }
};