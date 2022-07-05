my approach :
O(M*N)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> arr(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(arr[i][j]==0){
                    for(int k=0;k<matrix.size();k++){
                        matrix[k][j]=0;
                    }
                    for(int k=0;k<matrix[0].size();k++){
                        matrix[i][k]=0;
                    }
                }
            }
           
        }
    }
};



O(M+N):


 unordered_set<int> r,c;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(r.find(i)!=r.end() || c.find(j) != c.end()){
                    matrix[i][j]=0;
                }
          }
        }
        
        
        
        
 O(1) :
 
 
 
