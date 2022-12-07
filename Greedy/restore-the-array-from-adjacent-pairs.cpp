class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> hmap;
        int n = adjacentPairs.size()+1;
        for(auto x : adjacentPairs){
            hmap[x[0]].push_back(x[1]);
            hmap[x[1]].push_back(x[0]);
        }

        int head;
        for(auto x : hmap){
            if(x.second.size()==1){
                head=x.first;
                break;
            }
        }
        vector<int> res(n);
        res[0] = head;
        int prev;
        for(int i =1;i<n;i++){
            head = hmap[head].size()==1 ? hmap[head][0] : hmap[head][0]==prev ? hmap[head][1]  : hmap[head][0];
            res[i] = head;
            prev = res[i-1];
        }
        return res;
    }
};
