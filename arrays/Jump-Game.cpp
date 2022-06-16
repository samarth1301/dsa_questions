class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  =nums.size(),temp=0;

        if(n<=1){
            return true;
        }
        
        //APPROACH 1 

        //USE ONE FORLOOOP TO TRAVERSE EACH ELEMENT TILL THE SECOND LAST ELEMENT AND SEARCH FOR ZERO
        //IN CASE A ZERO IS FOUND USE WHILE LOOP TO FIND ANY ONE INDEX WHICH CAN OVER SHOOT THIS ZERO,
        //IF FOUND MOVE TO THE NEXT ELEMENT, ELSE RETURN FALSE AS THERE IS NO ELEMENT WHICH CAN OVERSHOOT THE RESPECTIVE ZERO.
        
//         for(int i=0;i<n-1;i++){
//             if(nums[i]==0){
//                 int j=i-1;
//                 while(j>=0 && nums[j]+j<=i){
//                     j--;
//                 }
//                 if(j<0){
//                     return false;
//                 }
                
//             }
          
//         }
        //return true;
        
        
        
        
        //APPROACH 2:
        //O(N)
        // USE ONE SINGLE LOOP AND TRAVERSE EACH ELEMENT TILL MAX INDX(INCLUDING MAX INDX), MAX INDX IS INITIALLY ZERO, AS INITIALLY WE CAN JUST TRAVERSE FIRST ELEMENT.
        //THEN IN EACH TRAVERSAL CHECK IF INCLUDING THE ELEMENT (INDX+ELEMENT) CAN INCR UR MAX INDX,
        //IF MAX INDX OVERSHOOTS THE SIZE OF THE ARRAY, RETURN TRUE, ELSE RETURN FALSE.
        
        int maxindx=0;
        for(int i=0;i<=maxindx;i++){
            int newindx = i+nums[i];
            maxindx = max(maxindx,newindx);
           // cout<<maxindx<<endl;
            if(maxindx>=n-1){
                return true;
            }
        }
        return false;
    }
};
