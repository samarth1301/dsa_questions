class Solution {
public:
    // O(N)
    int search(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;
        //(O(log(n)))
        int n = nums.size();
        int st=0,end = n-1;
        while(st<=end){
            int mid  = (st+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[st]<=nums[mid]){
               if(nums[st]<=target && target<=nums[mid]){
                        end=mid;
                }
                else{
                    st = mid+1;
                }
            }
            else{
                if(nums[mid]<target && target<= nums[end]){
                    st=mid+1;
                }
                else{
                    end=mid;
                }
            }
         
        }
        return -1;
    }
};
