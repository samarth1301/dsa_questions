class Solution {
public:
    int minDeletions(string s) {
       // unordered_map<char,int>count;
       //  unordered_map<int,int> countCount;
       //  for(auto e : s){
       //      count[e]++;
       //  }
       //  for(auto i :count){
       //      countCount[i.second]++;
       //  }
       //  int res=0;
       //  for(auto i:countCount){
       //      cout<<i.first<<" "<<i.second<<endl;
       //      while(i.second>1 && i.first!=0){
       //          i.second--;
       //          res++;
       //          int temp = i.first-1;
       //           while(countCount.find(temp)!=countCount.end() && temp>0){
       //               res++;
       //               temp--;
       //           }
       //          countCount[temp]++;
       //      }
       //  }
       //  return res;
        
//       unordered_map<char,int>count;
       
//         for(auto e : s){
//             count[e]++;
//         }
        
//         priority_queue<int> pq;
//         for(auto e : count){
//             pq.push(e.second);
//         }
        
//         int res=0;
//         while(pq.size()>1){
//             int topElement = pq.top();
//             pq.pop();
            
//             if(topElement == pq.top()){
//                 res++;
//                 if(topElement-1>0){
//                     pq.push(topElement-1);
//                 }
//             }
//         }
//         return res;
        int res=0;
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto c: mp){
            pq.push({c.second,c.first});
        }
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if(pq.empty()) break;
            if(temp.first!=0 && temp.first==pq.top().first){
                pq.push({--temp.first,temp.second});
                res++;
            }
        }
        return res;
    }
};     
