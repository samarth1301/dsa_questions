//first attempt
//O(m^2) 
//100% faster
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m= matrix[0].size(),l=0,r=m-1,t=0,b=n-1,indx=0;
        // vector<int> store(matrix[0].begin(),matrix[0].end());
        while(l<r && t<b){
            indx=0;
            vector<int> store;
            for(int i=l;i<=r;i++){
                store.push_back(matrix[t][i]);
            }
            for(int i=t;i<=b;i++){
                int temp = store[indx];
                store[indx] = matrix[i][r];
                matrix[i][r]= temp;
                indx++;
            }
            // for(auto i: store){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            
            // // r--;
            indx=0;
            for(int i=r;i>=l;i--){
                int temp = store[indx];
                if(i==r){
                    store[indx] = store.back();
                }
                else{
                    store[indx] = matrix[b][i];
                }
                
                matrix[b][i]= temp;
                indx++;
            }
         
            indx=0;
             for(int i=b;i>=t;i--){
                int temp = store[indx];
                 if(i==b){
                    
                     store[indx] = store.back();
                 }
                 else{
                     store[indx] = matrix[i][l];
                 }
                
                matrix[i][l]= temp;
                indx++;
            }
           // for(auto i: store){
           //      cout<<i<<" ";
           //  }
            // // b--;
             indx=0;
             for(int i=l;i<=r;i++){
                // int temp = store[indx];
            
                matrix[t][i]= store[indx];
                indx++;
            }
            t++;l++;r--;b--;
            
        }
    }
};
