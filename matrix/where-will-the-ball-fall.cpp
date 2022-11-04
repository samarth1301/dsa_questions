class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        // vector<int> result(grid[0].size(), 0);
        // for (int i = 0; i < grid[0].size(); i++) {
        //     result[i] = findBallDropColumn(0, i, grid);
        // }
        // return result;




        vector<int> res(grid[0].size(),-1);
        for(int i=0;i<grid[0].size();i++)
            res[i] = func(grid,i);
        return res;
    }

    int func(vector<vector<int>> &grid,int j){
        int i=0;
        while(i<grid.size() && j<grid[0].size() && j>=0){
            if(grid[i][j]==1){
                if(j<grid[0].size()-1 && grid[i][j+1]==-1) return -1;
                i++;j++;
                continue;
            }
            if(grid[i][j]==-1){
                if(j>0 && grid[i][j-1]==1) return -1;
                i++;j--;
            }
        }
        if(j>=grid[0].size() || j<0) return -1;
        return j;
    }

    int findBallDropColumn(int row, int col, vector<vector<int>>& grid) {
        // base case; ball reached the last row
        if (row == grid.size()) return col;
        int nextColumn = col + grid[row][col];
        if (nextColumn < 0 || nextColumn > grid[0].size() - 1 ||
            grid[row][col] != grid[row][nextColumn]) {
            return -1;
        }
        return findBallDropColumn(row + 1, nextColumn, grid);
    }
};
