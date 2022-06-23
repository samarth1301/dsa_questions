vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
    //     //code here        
    //     vector<long long int> arr;
    //     long long int mul=1;
    //     int c=0;
    //     for(auto i : nums){
    //         if(i==0){
    //             c++;
    //             continue;
    //         }
    //         if(i!=0)
    //             mul*=i;
    //     }
        
    //     if(c==0){
    //          for(int i=0;i<n;i++){
    //         long long int temp = mul/nums[i];
    //             arr.push_back(temp);
    //          }
    //          return arr;
    //     }
    //   if(c==1){
    //         for(int i=0;i<n;i++){
    //             if(nums[i]==0){
    //                 arr.push_back(mul);
    //             }
    //             else{
    //                  arr.push_back(0);
    //             }
    //       }
    //         return arr;
    //   }
    //     for(int i=0;i<n;i++){
    //              arr.push_back(0);
    //       }
       
    //     return arr;
    
    
    
    
    
    
    
    
    
    
    
    //////////////////////////////////method-2
        vector<long long int> arr(n,1);
        int temp=1;
        for(int i=0;i<n;i++){
            arr[i] = temp;
            temp*=nums[i];
        } 
        temp=1;
        for(int i=n-1;i>=0;i--){
            arr[i] = arr[i] * temp;
            temp = temp * nums[i];
        }
        
        return arr;
        
}
