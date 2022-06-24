class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //my O(N) approach
        int n= nums.size();
        // if(n==1){
        //     return 0;
        // }
        // if(nums[0]>nums[1]){
        //     return 0;
        // }
        // if(nums[n-2]<nums[n-1]){
        //     return n-1;
        // }
        // for(int i=1;i<n-1;i++){
        //     if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
        //         return i;
        //     }
        // }
        // return -1;
        
        
        
        //why O(N), when we can do it in O(log(n))
        
        return search(nums,0,n-1);
    }
    
    int search(vector<int> nums, int l, int r){
        if(l==r){
            return l;
        }
        int mid = (l+r)/2;
        if(nums[mid]>nums[mid+1]){
            return search(nums,l,mid);
        }
        return search(nums,mid+1,r);
    }
};
