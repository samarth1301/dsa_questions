class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {

        int n = board.size();
        vector<pair<int, int>> cell(n*n + 1);
        vector<int> col(n);
        iota(col.begin(),col.end(),0);
        int label = 1;
        for(int i = n-1;i>=0;i--){
            for(auto co : col){
                cell[label++] = {i,co};
            }
            reverse(col.begin(),col.end());
        }
        vector<int> dist(n*n+1,-1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i= curr+1;i<=min(curr+6, n*n);i++){
             int dest = board[cell[i].first][cell[i].second] !=-1 ? board[cell[i].first][cell[i].second] : i;
                if(dist[dest]==-1){
                    dist[dest] = dist[curr]+1;
                    q.push(dest);
                }

            }
        }
        return dist[n*n];
    //     vector<vector<int>> arr;
    //     for(int i=board.size()-1;i>=0;i--){
    //         vector<int> temp;
    //         if(arr.size()%2==0){
    //             for(int j=0;j<board[i].size();j++){
    //                 temp.push_back(board[i][j]);
    //             }       
    //         }
    //         else{
    //              for(int j=board[i].size()-1;j>=0;j--){
    //                 temp.push_back(board[i][j]);
    //             }
    //         }
    //         arr.push_back(temp);
    //     }
    //    int n = board.size();
    //    queue<vector<int>> q;

    //    q.push({1,0});
    //    int mn = INT_MAX;
    //     while(!q.empty()){
    //         vector<int> temp = q.front();
    //         q.pop();
    //         int node = temp[0], steps = temp[1];
    //         int r = node%n==0 ? (node/n)-1 : (node/n), c = (node%n==0) ? (n-1) :(node%n)-1;
    //         // if(node%n==0){
    //         //     r = (node/n)-1;
    //         //     // cout<<"we are here and r= "<<r<<endl;
    //         // }
    //         // else{
    //         //     r = node/n;
    //         // }
    //         if(arr[r][c]!=-1){
    //             node = arr[r][c];
    //         }
    //         cout<<"for node :"<<node<<" with steps: "<<steps<<endl;
    //         for(int j = node+1;j<=node+6 && j<=(n*n);j++){
    //             if(j==n*n){
    //                 cout<<j<<" "<<steps<<endl;
    //                 //  mn = min(steps+1,mn);
    //                 return steps+1;
    //             }
    //             // cout<<j<<" "<<steps<<endl;
    //             q.push({j,steps+1});
    //         }
    //     }
    //    return -1;
    }
};
