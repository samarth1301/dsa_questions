class Solution {
public:
int getNextDaysIdx(vector<int>&days, int daysIdx, int ticketDuration)
    {
        int target = days[daysIdx] + ticketDuration - 1;
        for (int i = daysIdx + 1; i < days.size(); i++)
        {
            if (days[i] > target) return i;
        }
        return days.size();
    }
    int recur(vector<int>& days, vector<int>& costs, vector<int> &dp, int i, int limit){
        if(i>=days.size()) return 0;
        // cout<<i<<endl;
        if(dp[i]!=-1) return dp[i];
        // if(days[i]<limit) return dp[i] = recur(days,costs,dp,i+1,limit);
        int mn=INT_MAX;
        for(int j=0;j<3;j++){
            switch (j){
                case 0:
                mn = min(mn,recur(days,costs,dp,getNextDaysIdx(days, i, 1),days[i]+1)+costs[j]);
                break;
                case 1:
                mn = min(mn,recur(days,costs,dp,getNextDaysIdx(days, i, 7),days[i]+7)+costs[j]);
                break;
                case 2:
                mn = min(mn,recur(days,costs,dp,getNextDaysIdx(days, i, 30),days[i]+30)+costs[j]);
                break;
                default:
                break;
            }
        }
        return dp[i] = mn;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return recur(days,costs,dp,0,0);
    }
};
