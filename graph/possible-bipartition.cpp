class Solution {
public:
    
    // here color is basically a set, and we need to seperate all the vertices into bipartition set
  //where no vertex from the same set will have any edge connecting it
    bool recur(vector<vector<int>> & arr,int i, vector<int> & color){
        queue<int>q;
        color[i] = 0;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
          //for each vertex, if its color is same as its neighbours, return false
          //else add the vertex in queue, and give alternate color to this vertex
          
            for(auto vertices:arr[x]){
                if(color[vertices]==color[x]) return false;
                if(color[vertices]==-1){
                    q.push(vertices);
                    color[vertices] = 1 - color[x];
                }
            }
        }
       
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {



        vector<vector<int>> arr(n+1);
        vector<int> color(n+1,-1);
      //create adjacency matrix
        for(auto i: dislikes){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        //for each vertex if it is not colored, apply bfs from that vertex and give alternate colors to each neighbour.
        for(int i=1;i<n+1;i++){
            if(color[i]==-1){
                if(!recur(arr,i,color)) return false;
            }
        }

        return true;

       
    }
};
