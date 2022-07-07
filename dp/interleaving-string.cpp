class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
//         int i = 0,j=0,k=0;
//         int n1 = s1.size(), n2 = s2.size(),n3=s3.size();
//         while(i<n1 && j<n2){
//             if(s1[i]==s3[k]){
//                 i++;
//             }
//             else if(s2[j]==s3[k]){
//                 j++;
//             }
//             else{
//                 return false;
//             }
//             k++;

//         }
//        cout<<i<<" "<<j<<" "<<k<<endl;
//         while(i<n1 ){
//             if(s1[i]!=s3[k]) return false;
//             i++;
//             k++;
//         }
//         while(j<n2){
//             if(s2[j]!=s3[k]) return false;
//             j++;
//             k++;
//         }
//         return true;
        //recursive solution with memoization
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));
        if(s1.size()+s2.size()!=s3.size())
            return false;
        return rec(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1,dp);
        
        
        
    }
    bool rec(string s1, string s2, string s3, int i, int j, int k,vector<vector<int>>& dp){
        if(i<0 && j<0 && k<0) return true;
        if(i>=0 && j>=0 && dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i>=0 && s1[i]==s3[k] && j>=0 && s2[j]==s3[k])
        {
            return dp[i][j]=rec(s1,s2,s3,i-1,j,k-1,dp) || rec(s1,s2,s3,i,j-1,k-1,dp);
        }
         if(i>=0 && s1[i]==s3[k])
        {
            return rec(s1,s2,s3,i-1,j,k-1,dp) ;
        }
         if(j>=0 && s2[j]==s3[k])
        {
            return (rec(s1,s2,s3,i,j-1,k-1,dp));
        }
        return false;
    }
};
