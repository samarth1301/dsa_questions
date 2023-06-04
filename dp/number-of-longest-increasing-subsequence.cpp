class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res =0;
        vector<int> dp(n,1), c(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    c[i] = c[j];
                }
                else if(nums[i]>=nums[j] && dp[i]==dp[j]+1){
                    c[i] += c[j];
                }
            }
            res = max(res, dp[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==res) ans+=c[i]; 
        }
        return ans;
    }
};
