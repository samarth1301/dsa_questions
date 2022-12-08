class Solution {
public:
    string removeKdigits(string num, int k) {
        //ans string
      string res="";
      for(auto c : num){//iterate each character
      //if you are able to find a character in res which is greater than present character
    //   remove the character
          while(res.size()!=0 && res.back()>c && k){
              res.pop_back();
              k--;
          }
          //add present character in res only if no trailing zeroes
          if(res.size()!=0 || c!='0'){
              res.push_back(c);
          }
      }
      //if still need to remove some character, remove from back.
      while(res.size()!=0 && k){
          res.pop_back();
          k--;
      }
      return res.empty() ? "0" : res;
    }
};
