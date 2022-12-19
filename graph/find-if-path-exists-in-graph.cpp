class Solution {
public:
    vector<int> visited;
     bool recur(unordered_map<int,vector<int>>& graph,int s, int d){
         if(visited[s]==1) return false;
         if(s==d) return true;
        //  if(graph[s][d]==1) return true;
         visited[s]=1;
        //  for(int i=0;i<graph[s].size();i++){
        //      if(graph[s][i]==1){
        //          bool ans = recur(graph,i,d);
        //         if(ans) return true;
        //      }
        //  }
        for(auto vertex : graph[s]){
            if(recur(graph,vertex,d)) return true;
        }
         return false;
     }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // int mn = 0, mx = 0;
        // for(auto x : edges){
        //     mn = min({mn,x[0],x[1]});
        //     mx = max({mx,x[0],x[1]});
        // }
        visited.resize(n,0);
        unordered_map<int,vector<int>> arr;
        for(auto x : edges){
            arr[x[0]].push_back(x[1]);
            arr[x[1]].push_back(x[0]);
        }
        // for(auto x : arr){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return recur(arr,source,destination);
        // return true;
    }
};
