//basic idea is to traverse the edge elements and apply dfs to each element which is greater than the present element
//and keep marking each element as true if u can visit it with respect to atlantic and pacific ocean

class Solution {
public:
    int m, n;
	// denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool> > atlantic, pacific;
	vector<vector<int> > ans;    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& arr) {
//         int m = arr.size(),n=arr[0].size();
//         atlantic = pacific = vector<vector<bool>> (m,vector<bool>(n,false));
//         for(int i = 0 ; i<m;i++){
//             dfs(arr,pacific,i,0);
//             dfs(arr,atlantic,i,n-1);
//         }
//         for(int i = 0 ; i<n;i++){
//             dfs(arr,pacific,0,i);
//             dfs(arr,atlantic,m-1,i);
//         }
        
        
// 		// if(!size(mat)) return ans;
// 		// m = size(mat), n = size(mat[0]);
// 		// atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
// 		// // perform dfs from all edge cells (ocean-connected cells)
// 		// for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
// 		// for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
// 		return ans;
        
        int m = arr.size(),n =arr[0].size();
        atlantic = pacific = vector<vector<bool>> (m,vector<bool> (n,false));
        for(int i =0 ; i <m;i++){
            dfs(arr,pacific,i,0);
            dfs(arr,atlantic,i,n-1);
        }
        for(int i =0 ; i <n;i++){
            dfs(arr,pacific,0,i);
            dfs(arr,atlantic,m-1,i);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& arr,vector<vector<bool>> &visited, int i, int j){
        if(visited[i][j]) return;
        visited[i][j] = true;\
            int m = arr.size(),n=arr[0].size();
        if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
        if(i+1<m && arr[i+1][j]>=arr[i][j]) dfs(arr,visited,i+1,j);
        if(i-1>=0 && arr[i-1][j]>=arr[i][j]) dfs(arr,visited,i-1,j);
        if(j+1<n && arr[i][j+1]>=arr[i][j]) dfs(arr,visited,i,j+1);
        if(j-1>=0 && arr[i][j-1]>=arr[i][j]) dfs(arr,visited,i,j-1);
    }
//     void dfs(vector<vector<int>>& arr, vector<vector<bool>> &visited,int i, int j){
//       if(i<0 || i>=arr.size() || j<0 || j>=arr[0].size()) return;
//         if(visited[i][j]) return;
//         visited[i][j]=true;
//         if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
//         if(i+1<arr.size() && arr[i+1][j]>=arr[i][j])dfs(arr,visited,i+1,j);
//          if(i-1>=0 && arr[i-1][j]>=arr[i][j])dfs(arr,visited,i-1,j);
//          if(j+1<arr[0].size() && arr[i][j+1]>=arr[i][j])dfs(arr,visited,i,j+1);
//         if(j-1>=0 && arr[i][j-1]>=arr[i][j])dfs(arr,visited,i,j-1);
         
//     }
//     void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
//         if(visited[i][j]) return;
//         visited[i][j] = true;
// 		// if cell reachable from both the oceans, insert into final answer vector
//         if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
// 		// dfs from current cell only if height of next cell is greater
// /*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
// /*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
// /*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
// /*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
//     }
};
