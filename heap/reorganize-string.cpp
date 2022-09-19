class Solution {
public:
    string reorganizeString(string s) {
        
        //we will use max heap here with 
        //count of each character and its value
        // and will append each max frequent element
       // as long as we have more than one character in our pq(heap)
        //but when the most frequent element comes again
        //we will simply pop another element and add it 
        // and push both elements again into the heap
        //but will decrement the count of one character
        //the one added into the ans
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto c: s){
            mp[c]++;
        }
        for(auto itr: mp){
            pq.push({itr.second,itr.first});
        }
        string res;
        while(pq.size()>1){
            auto temp = pq.top();
            pq.pop();
            if(temp.second==res.back()){
                if(!pq.empty()){
                    auto temp2 = pq.top();
                    pq.pop();
                    res+=temp2.second;
                    temp2.first--;
                    if(temp2.first!=0) pq.push({temp2.first,temp2.second});
                }
            }
            else{
                  res+= temp.second;
                  temp.first--;
            }
            //only add again if its frequency is not 0
          if(temp.first!=0){
              pq.push({temp.first,temp.second});
          }
            
        }
        //if the character is still left with more than one
        //frequency than it is not possible to create 
        // a required string
        //also if it is the same as the last char of result string
        if(pq.top().first!=1 || pq.top().second == res.back()) return "";
        //else add the final char and return the ans
        res+=pq.top().second;
        return res;
    }
};
