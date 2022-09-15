class Solution {
public:
    //we will solve this question in reverese manner using the target string 
    //and breaking it down in each step into possible quesiton marks
    
  vector<int> movesToStamp(string stamp, string target) {
     //result array
      vector<int> res;
    //number of question marks
      int count =0;
        //if we dont maintain a visited array it will traverse the same position
      //infinitely
      vector<bool>visited(target.length(),false);
      //as long as all char in string are not question marks
      while(count!=target.length()){
          //in each iteration we need to check for a possibility when no 
          //more characters can be replaced with ? with the given stamp
          bool temp = false;
          // we will traverse in the entire target string and look for
          //an unvisited index with possible match
          for(int i = 0 ; i <= target.length()-stamp.length();i++){
            
              if(!visited[i] && check(target,stamp,i)){
                  //replace all char with ?
                  count = replace(target,i,stamp.size(),count);
                  //this index has been visited and need not to be visit again
                  visited[i] = true;
                  //one match was found so no need to return empty array
                  temp = true;
                  res.push_back(i);
              }
                //in case all char are ?              
              if(count==target.length()) break;
          }
          //if no match found
          if(!temp) return {};
      }
      //we did this question in reverse order so we need to reverse the array
      reverse(res.begin(),res.end());
      return res;
}
    int replace(string &target,int pos,int size,int c){
        
        for(int i=0;i<size;i++){
            if(target[i+pos]!='?') {target[pos+i]='?';c++;}
        }
        return c;
    }
    bool check(string &target,string &stamp,int pos){
        //if matching character or ? found continue the loop and return true
        for(int i =0;i<stamp.size();i++){
            if(target[i+pos]!='?' && target[i+pos]!=stamp[i]) return false;
        }
        return true;
    }
};
