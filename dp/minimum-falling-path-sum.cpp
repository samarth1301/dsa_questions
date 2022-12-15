class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& A) {
       int res=INT_MAX;
       if(A.size()==0 || A[0].size()==0) return 0;
       for(int i=1;i<A.size();i++){
           for(int j=0;j<A[0].size();j++){
               int mn = A[i-1][j];
               if(j>0){
                   mn = min(mn,A[i-1][j-1]);
               }
               if(j<A[0].size()-1){
                   mn = min(mn,A[i-1][j+1]);
               }
               A[i][j] += mn;
           }
       }

        for(auto i : A[A.size()-1]){
            // cout<<i<<endl;
            res = min(res,i);
        }
        return res;

    
}
};
