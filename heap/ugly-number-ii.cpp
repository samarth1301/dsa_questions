class Solution {
public:
    int nthUglyNumber(int n) {
//         int i =1;
//         if(n==1) return 1;
//         n--;
//         while(n){
            
//             if((i%2==0 ||i%3==0 || i%5==0)){
//                 int temp = i;
//                 while(temp%2==0 ){
//                     temp/=2;
//                 }
//                  while((temp%3==0)){
//                     temp/=3;
//                 }
//                  while(( temp%5==0)){
//                     temp/=5;
//                 }
//                   if(temp==1){
//                       n--;
//                      if(n==0) return i;
//                   }
               
              
//             }
//             i++;
//         }
//         return i;
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        pq.push(1);
        int res = 0;
        // n++;
        while(n){
            auto temp = pq.top();
            res=temp;
            while(!pq.empty() && pq.top()==temp){
                pq.pop();
            }
            pq.push( long (temp*2));
            pq.push(long (temp*3));
            pq.push(long (temp*5));
            n--;
        }
        return res;
    }
};
