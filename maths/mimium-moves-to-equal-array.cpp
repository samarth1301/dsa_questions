class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int max = max_element(nums.begin(),nums.end())-nums.begin();
        // int min  = *min_element(nums.begin(),nums.end());
        // int c=0;
//         while(nums[max]!=nums[min]){
//             int diff = nums[max]-nums[min];
//             for(int i=0;i<nums.size();i++){
//                 if(i!=max){
//                     nums[i]+=diff;
//                 }
//             }
//             c+=diff;
//            max = max_element(nums.begin(),nums.end())-nums.begin();
//             min  = min_element(nums.begin(),nums.end())-nums.begin();
            
//         }
        
        
        
        
        
        
        
        
        
        
        
        
        
        //find minimum element in the array
        //accumulate all the elements in the array
        //basic idea is 
        //we are calculating the diff of each element with the minimum element
        //and adding it into the result as we need to do that many operations
        
        
        
        
        
        int min = *min_element(nums.begin(),nums.end());
        int c = accumulate(nums.begin(),nums.end(),0);
        return c - (min*nums.size());
        
        
        // return c;
    }
};
