class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> s) {
        // long dp[501] = {startFuel};
        // for (int i = 0; i < s.size(); ++i)
        //     for (int t = i; t >= 0 && dp[t] >= s[i][0]; --t)
        //         dp[t + 1] = max(dp[t + 1], dp[t] + s[i][1]);
        // for (int t = 0; t <= s.size(); ++t)
        //     if (dp[t] >= target) return t;
        // return -1;
      //   if(s.size()==0 && target>startFuel) return -1;
      //   int i =0 , res =0 ;
      //   priority_queue<int> pq;
      //   for(res=0; startFuel<target;res++){
      //      while(i<s.size() && s[i][0]<=startFuel){
      //           pq.push(s[i++][1]);
      //           // res++;
      //       }
      //       if(pq.empty()) return -1;
      //       startFuel += pq.top();pq.pop();
      //   }
      // return res;
       vector<long long int> dp(s.size()+1,0);
        dp[0] = startFuel;
        for(int i =0 ; i < s.size() ; i++){
            for(int j = i ; j>=0;j--){
                if(dp[j]>=s[i][0]){
                    dp[j+1]= max(dp[j+1],dp[j] + s[i][1]);
                }
            }
        }
       
        for(int i=0; i<dp.size();i++){
            // cout<<dp[i]<<endl;
            if(dp[i]>=target) return i;
        }
        return -1;
    }
   
};
