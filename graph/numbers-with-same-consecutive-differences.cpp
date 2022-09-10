class Solution {
public:
    vector<int> res;

    vector<int> numsSameConsecDiff(int n, int k) {
        // vector<int> res;
//         for(int i= 1 ; i <=9 ; i++){
//             if(i+k<=9){
//                 int temp = 0;
//                 int j =1;
//                 while(j<=n){
//                     temp = j%2==0 ? temp*10 + (i+k) : (temp*10 + i);
//                     j++;
//                 }
//                 res.push_back(temp);
//             }
//             if(k!=0 && i-k>=0){
//                 int temp = 0;
//                 int j = 1;
//                 while(j<=n){
//                     temp = j%2==0 ? temp*10 + (i-k) : (temp*10 + i);
//                     j++;
//                 }
//                 res.push_back(temp);

//             }
//         }
        // for(int  i = 1;i<10;i++){
        //     dfs(n-1,i,k,res);
        // }
        // return res;
        
        //use recursive function for each digit from 1-9
        //each with n-1 digits left, as we have already selected 
        //1 digit here
        
        for(int i =1;i<10;i++){
            dfs(n-1,i,k);
        }
        return res;
    }
    void dfs(int n,int val,int k){
        //if we have utilised all available digits
        //add it to result vector and return
        if(n<=0) {
            res.push_back(val);
            return;
        }
        //else take the last digit from the number and check if 
        //we can include temp+k and temp-k in range [0,9]
        //if so call the recursive function again adding the value 
        //in the number and reducing the digit
        int temp = val%10;
        int a = temp+k;
        if(a<10){
            dfs(n-1,val*10 + a,k);
        }
        int b = temp-k;
        //if k==0 we have already counted this digit in above recursion
        if(b>=0 && k!=0){
            dfs(n-1,val*10 + b,k);
        }
        
    }
  
};
