
//question link - https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
         // O(N)
        
        bool check = true;
        int maxTill = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1] ){
                if(check){
                    if(i+2<n && nums[i+2]<nums[i]){
                         if((nums[i+1])<maxTill) return false;
                         nums[i]=nums[i+1]-1;
                    }
                    else if(i+2<n && nums[i+2]>=nums[i]){
                        nums[i+1]=nums[i];
                    }
                   
                    check = false;
                }
                else{
                    return false;
                }
            }
                maxTill = max(maxTill,nums[i]); 
        }
        return true;
        
        // O(log(n))

        // return compute(nums,0,nums.size()-1);
    }
    
    
    
//     bool compute(vector<int> nums,int st, int end){
//         if(st==end){
//             if(st-2<0){
//                 return true;
//             }
//             if(nums[st-1]<=nums[st+1]){
//                 return true;
//             }
//             return(nums[st-2]<=nums[st]);
//         }
//         int mid =(st+end)/2;
//         if(nums[mid]>nums[mid+1]){
//             return compute(nums,mid+1,end);
//         }
//         else{
//             return compute(nums,st,mid);
//         }
        
//     }
    
};
