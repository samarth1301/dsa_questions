class Solution {
public:
    vector<int> dp;

    int helper(vector<int> nums,int t){
        if(t==0) return 1;
        if(dp[t]!=-1) return dp[t];
        
        int res = 0;
        for(int el : nums){
            if(el<=t){
                res+=helper(nums,t-el);
            }
        }
        return dp[t] = res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        return helper(nums,target);
    }
};
