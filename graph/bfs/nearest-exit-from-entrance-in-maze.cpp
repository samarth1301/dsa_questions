class Solution {
public:
   

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        //elements inside your queue will have 3 elements
        queue<array<int,3>> q;
        q.push({entrance[0],entrance[1],0});
        maze[entrance[0]][entrance[1]] = '+';
        vector<pair<int,int>> arr;
        arr.push_back({-1,0});
        arr.push_back({1,0});
        arr.push_back({0,-1});
        arr.push_back({0,1});

        while(!q.empty()){
            auto [i,j,dis] = q.front();
            q.pop();
            for(auto p : arr){
                int nxtr = i+p.first;
                int nxtc = j+p.second;
                if(nxtr>-1 && nxtr<maze.size() && nxtc>-1 && nxtc<maze[0].size() && maze[nxtr][nxtc]=='.'){
                    if(nxtr==0 || nxtr == maze.size()-1 || nxtc == 0 || nxtc== maze[0].size()-1) return dis+1;
                    maze[nxtr][nxtc] = '+';
                    q.push({nxtr,nxtc,dis+1});
                }
            }
        }
        return -1;
    }
};
