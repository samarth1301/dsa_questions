class Solution {
public:
    int res = INT_MAX;

    void dfs(vector<vector<int>> &adj, int i, int dst, int k, int dis){
        if(i==dst){
            res = min(res, dis);
        }
        if(k<0) return;
        for(int j = 0;j<adj[i].size();j++){
            if(adj[i][j]!=-1){
                dfs(adj,j,dst,k-1,dis+adj[i][j]);
            }
        }
        
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance from source to all other nodes.
        // vector<vector<int>> adj(n, vector<int> (n,-1));
        // for(auto flight : flights){
        //     adj[flight[0]][flight[1]] = flight[2]; 
        // }
        // dfs(adj,src,dst,k,0);
        // return res == INT_MAX ? -1 : res;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> temp(dist);
            for(auto flight: flights){
                if(dist[flight[0]]!=INT_MAX){
                    temp[flight[1]] = min(temp[flight[1]],dist[flight[0]]+flight[2]);
                }
            }
            dist= temp;
        }

        return dist[dst] == INT_MAX ? -1: dist[dst];







        // vector<int> dist(n, numeric_limits<int>::max());
        // dist[src] = 0;

        // // Run only K+1 times since we want shortest distance in K hops.
        // for (int i = 0; i <= k; i++) {
        //     // Create a copy of dist vector.
        //     vector<int> temp(dist);
        //     for (auto& flight : flights) {
        //         if (dist[flight[0]] != numeric_limits<int>::max()) {
        //             temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
        //         }
        //     }
        //     // Copy the temp vector into dist.
        //     dist = temp;
        // }
        // return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
