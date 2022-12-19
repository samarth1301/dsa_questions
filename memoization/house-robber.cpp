class Solution {
public:
    int ans = INT_MIN;
    vector<int> dp;

    int recur(vector<int>& nums, int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int res = INT_MIN;
        res = max(res,nums[i]+recur(nums,i+2));
        res = max(res,nums[i]+recur(nums,i+3));
        return dp[i] = res;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return max(recur(nums,0),recur(nums,1));
        // n = nums.size();
        // cache = vector<int>(n, -1);
        // return max(rob(nums, 0), rob(nums, 1));
    }
};
