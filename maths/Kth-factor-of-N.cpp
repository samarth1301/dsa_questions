class Solution {
public:
    int kthFactor(int n, int k) {
        //my first approach
//         int c=1;
//         if(k==1)
//             return 1;
//         for(int i=2;i<=(n/2);i++){
//             if(n%i==0){
//                // while(n%i==0){
//                //     n/=i;
//                // }   
//                 c++;
//             }
//             if(c==k){
//                 return i;
//             }    
//         }
//         // cout<<c<<endl;
//         if(c+1==k){
//             return n;
//         }
            
//         return -1;
        
        
//         another said optimized approach, but idts
        vector <int> arr;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                arr.push_back(i);
        }
        if(arr.size()<k){
            return -1;
        }
        return arr[k-1];
    }
};
