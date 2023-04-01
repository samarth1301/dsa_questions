class Solution {
public:

    void dfs(vector<vector<int>> &adj, vector<int> &vis, int i){
        vis[i]=1;
        for(auto j : adj[i]){
            if(!vis[j]){
                dfs(adj,vis,j);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                res++;
            }
        }
        return res-1;
    }
};
