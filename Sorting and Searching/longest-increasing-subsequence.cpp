class Solution {
public:
 
    int lengthOfLIS(vector<int>& nums) {
//         int mx = INT_MIN, n = nums.size();
//         vector<int> dp(n,1);
//         for(int i =0 ; i <n-1 ; i++){
//             for(int j = i + 1 ; j < n;j++){
//                 if(nums[j]>nums[i]){
//                     dp[j] = max(dp[j],dp[i]+1);
//                 }
//             }
        
//         }
//         return *max_element(dp.begin(),dp.end());
     
        
        // link: https://leetcode.com/problems/longest-increasing-subsequence/submissions/
        int n = nums.size();
        // vector<int> dp(n,1);
        // for(int i = 0;i<n-1;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(nums[j]>nums[i]){
        //             dp[j] = max(dp[j],dp[i]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        int len = 0;
        for(auto i : nums){
            if(len==0 || nums[len-1]<i){
                nums[len++] = i;
            }
            else{
                *lower_bound(nums.begin(),nums.begin()+len,i) = i;
            }
        }
        return len;
    }
};
