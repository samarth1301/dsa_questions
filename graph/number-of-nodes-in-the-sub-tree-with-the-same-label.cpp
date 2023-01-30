class Solution {
public:
//   vector<int> fun(vector<vector<int>> &adj, string &labels, int i,vector<int>&result){
//     vector<int> ans(26, 0);
//     result[i] = 1;
//     ans[labels[i] - 'a'] = 1;
    
//     for(int j = 0; j != adj[i].size(); j++)
//       if(!result[adj[i][j]]){
//         vector<int> tmp = fun(adj, labels,adj[i][j],result);
//         for(int k = 0; k != 26; k++) ans[k] += tmp[k];
//       }
    
//     result[i] = ans[labels[i] - 'a'];
    
//     return ans;
//   }
  vector<int> recur(vector<vector<int>> &arr, vector<int> &res, int i, string &label){
    //   if(i>arr.size()) return;
      res[i]=1;
        vector<int> hmap(26,0);
      hmap[label[i]-'a']=1;
      for(auto j:arr[i]){
          if(!res[j]){
             auto temp = recur(arr,res,j,label);
             for(int k=0;k<26;k++){hmap[k]+=temp[k];}
          }
      }
        res[i] = hmap[label[i]-'a']; 
      return hmap;
  }
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

    
      vector<vector<int>> arr(n);
      for(auto i : edges){
         
              arr[i[0]].push_back(i[1]);
              arr[i[1]].push_back(i[0]);
         
      }

        vector<int> res(n,0);
        recur(arr,res,0, labels);

       
        return res;

        











    // vector<vector<int>> adj(n);
    // vector<int> result(n,0);
    // for(int i = 0; i != edges.size(); i++)
    //  {adj[edges[i][0]].push_back(edges[i][1]);
    //   adj[edges[i][1]].push_back(edges[i][0]);
    //  }
    
    // fun(adj, labels, 0,result);
    // return result;
  }
};
