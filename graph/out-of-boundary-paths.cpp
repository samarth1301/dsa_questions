class Solution {
public:
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return findPaths(m,n,maxMove,startRow,startColumn,dp);
    }
   
    int findPaths(int m, int n, int maxMove,int i, int j, vector<vector<vector<int>>> &dp){
        if(i>=m || j>=n || i<0 || j<0) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
                int mod=1e9+7;

        return dp[i][j][maxMove]=
            ((findPaths(m,n,maxMove-1,i+1,j,dp)+
            findPaths(m,n,maxMove-1,i,j+1,dp))%mod+
            (findPaths(m,n,maxMove-1,i,j-1,dp)+
            findPaths(m,n,maxMove-1,i-1,j,dp))%mod)%mod;
    }
};
