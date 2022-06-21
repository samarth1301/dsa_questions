class Solution {
  public:
    bool isPossible(long long a[], long long b[], long long n, long long k) {
        // Your code goes here
        //my code
      //wrong- your sum can be greater than k too.
        // unordered_map<long long,long long> hmap;
        // for(int i =0 ;i<n;i++){
        //     hmap[a[i]]++;
        // }
        
        
        // for(int i =0 ;i<n;i++){
        //     if(hmap.find(k-b[i])!=hmap.end()){
        //         if(hmap[k-b[i]]>0){
        //             hmap[k-b[i]]--;
        //             continue;
        //         }
        //         return false;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        
        // return true;
        
        // ////////////////////////////////////////////////////////////////////////
        // //sort one array in asc
        sort(a,a+n);
        //this will give us max value for all elements
        //if any one number is less than k, return false
        //sort second element in desc
        sort(b,b+n,greater<long long>());
        
        for(int i=0;i<n;i++){
            if(a[i]+b[i]<k){
                return false;
            }
        }
        
        return true;
        
        
    }
};
