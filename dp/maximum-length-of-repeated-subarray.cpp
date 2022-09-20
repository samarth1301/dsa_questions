class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    //here we store the largest value of equal subarrays
      //in DP matrix we start traversing from the right and
      //each time an equal values is observed in both the arrays
      //we assign dp[i+1][j+1]+1 value to dp[i][j]
      //as if the next values were same too
      //we can add one more value in the same subarray
      //or else 0+1 will be one for the current value.
        
        
        
        
        
        
        
        
        //DP
        int mx = 0;
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                }
                mx = max(mx,dp[i][j]);
            }
        }            
        return mx;
        
        
        
        
        
        
        
        
    }
};
