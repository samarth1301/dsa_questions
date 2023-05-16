#include <bits/stdc++.h> 
int f(int i, int w, vector<int> &wv, vector<int> &vv, vector<vector<int>> &dp){
	// if(i<0 || w<=0){
	// 	return 0;
	// }
	if(w==0) return 0;
	if(i==0){
		
		if(w>=wv[0]){
			return vv[0]; 
		}
		return 0;
	}
			
	if(dp[i][w]!=-1) return dp[i][w];
	
	int notPick = f(i-1, w, wv,vv,dp);
	int pick = INT_MIN;
	if(w-wv[i]>=0) pick = f(i-1, w-wv[i], wv, vv, dp) + vv[i];
	return dp[i][w] = max(pick, notPick);
}
int knapsack(vector<int> wv, vector<int> vv, int n, int w) 
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (w+1,-1));
	//recursion
	return f(n-1, w, wv, vv, dp);
	//iteration
	// for(int j =wv[0];j<=w;j++){
	// 	dp[0][j] = vv[0];
	// }

	// for(int i=1;i<n;i++){
	// 	for(int j=1;j<=w;j++){
	// 		int a = dp[i-1][j], b = INT_MIN;
	// 		if(j-wv[i]>=0)b = dp[i-1][j-wv[i]] + vv[i];
	// 		dp[i][j] = max(a,b);
	// 	}
	// }
	// // for(int i=0;i<n;i++){
	// // 	for(int j=0;j<=w;j++){
			
	// // 		cout<<(dp[i][j])<<" " ;
	// // 	}
	// // 	cout<<endl;
	// // }
	// return dp[n-1][w];
}
