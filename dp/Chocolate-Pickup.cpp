//this is a hard 3-D DP problem

#include <bits/stdc++.h>
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size()) return 0;
    if(i==grid.size()-1){
        if(j1==j2) return grid[i][j1];
        return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int mx = INT_MIN;
    for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
            int idx1 = j1-1+k, idx2 = j2-1+l;

            int temp = f(i+1,idx1,idx2,grid,dp);
            if(j1==j2) mx = max(mx,grid[i][j1]+temp);
            else {
              mx = max(mx, temp + grid[i][j1]  + grid[i][j2]);
            }
        }
    }
    return dp[i][j1][j2] = mx;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c,vector<int>(c,-1)));
    //recursive
    // return (f(0,0, c-1,grid,dp));
    //iterative
    for(int j1=0;j1<c;j1++){
      for (int j2 = 0; j2 < c; j2++) {
          if(j1==j2){
            dp[r-1][j1][j2] = grid[r-1][j1];
          }
          else{
            dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];

          }
      }
    }
    for(int i =r-2;i>=0;i--){
         for(int j1=0;j1<c;j1++){
           for (int j2 = 0; j2 < c; j2++) {
               int mx = INT_MIN;
               for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    int idx1 = j1-1+k, idx2 = j2-1+l;
                    int temp = 0;
                    if(idx1<0 || idx2<0 || idx1>=c || idx2>=c) temp = -1e8;
                    else temp = dp[i+1][idx1][idx2];
                    if(j1==j2) mx = max(mx,grid[i][j1]+temp);
                    else {
                      mx = max(mx, temp + grid[i][j1] + grid[i][j2]);
                    }
                }
                }
                dp[i][j1][j2] = mx;
    }
           }
         }
    
    return dp[0][0][c-1];
}
