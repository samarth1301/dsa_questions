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
        
      unordered_map<char,int>count;
       
        for(auto e : s){
            count[e]++;
        }
        
        priority_queue<int> pq;
        for(auto e : count){
            pq.push(e.second);
        }
        
        int res=0;
        while(pq.size()>1){
            int topElement = pq.top();
            pq.pop();
            
            if(topElement == pq.top()){
                res++;
                if(topElement-1>0){
                    pq.push(topElement-1);
                }
            }
        }
        return res;
    }
};     
