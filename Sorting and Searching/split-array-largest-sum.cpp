class Solution {
public:
    
    static int helper(vector<int> nums, int m){
        int count = 0,sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]>m){
                sum=nums[i];
                count++;
            }
            else{
                sum+=nums[i];
            }
        }
        count++;
        return count;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n =nums.size();
      //low is max element, high is the total sum
        int low  = *max_element(nums.begin(),nums.end()),high = accumulate(nums.begin(),nums.end(),0);
        int ans = (low+high)/2,mid=0;
      //binary search for the ans
        while(low<=high){
            mid = (low+high)/2;
            int c = helper(nums,mid);
          //in case number of subarrays is less than m, you can minimise the value of ans by lowering your high value and updating the 
          //ans to the mid value 
            if(c<=m){                
                high = mid-1;
                ans = mid;
            }
            else{                
                low = mid+1;
            }
        }
        return ans;
    }
};
