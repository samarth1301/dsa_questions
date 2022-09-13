class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // sort(tokens.begin(), tokens.end());
        // int res = 0, points = 0, i = 0, j = tokens.size() - 1;
        // while (i <= j) {
        //     if (P >= tokens[i]) {
        //         P -= tokens[i++];
        //         res = max(res, ++points);
        //     } else if (points > 0) {
        //         points--;
        //         P += tokens[j--];
        //     } else {
        //         break;
        //     }
        // }
        // return res;
        
        
        
        //sort the array
      //then have two pointers, one at the start 
      //one at the end, and start traversing 
      //if arr[i] is less than or equal to power 
      //than inc i and remove that value from powwe
      //we need the max points so store it in res
      
      
      
      //in case u cant add a point from left
      //add power from right (when you have points)
      
//       otherwise break the loop as we cant access the left element neither we can add power from right
      //so just return res
        
       sort(tokens.begin(),tokens.end());
        int i =0,j=tokens.size()-1,res=0,points=0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i++];
                res=max(res,++points);
            }
            else if(points>0){
                power+=tokens[j--];
                points--;
            }
            else{
                break;
            }
        }
        
        return res;
        
        
        
        
    }
};;
