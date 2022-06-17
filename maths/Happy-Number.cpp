class Solution {
public:
    bool isHappy(int n) {
        //my first approach- passed
//         int c=0;
//         while(c<1000){
//             int sum=0;
//             while(n>0){
//                  sum += (n%10)*(n%10);
//                 n/=10;
//             }
           
//             if(sum==1){
//                 return true;
//             }
//             n=sum;
//             c++;
//         }
        // return false;
        
        
        // ______________________________________________________
//         0ms 100% faster
        //you can use hash map to store each number coming
            //if any number repeats
            //you can come out of the loop and return false
            //if number becomes 1 
            //you can come out of the loop and return true
            //as there can be just two conditions
            //either number becomes one or stucks in a cycle
            //it will never overshoot 1053 in case of largest number 9999999999999
            //thus if it cant be happy it will stuck in a cycle
        
//         unordered_set<int> hmap;
//         while(n!=1 && hmap.find(n)==hmap.end()){
          
//             int sum = 0,temp=n;
            
//             while(temp>0){
//                 sum+=(temp%10)*(temp%10);
//                 temp/=10;
//             }
//             hmap.insert(n);
//             n=sum;
          
//         }
//         return n==1;
            
            
//             ______________________________________________________________________
            
            
            
//             one more method is using slow runner and fast runner
            
        int slow = n;
        int fast = rec(n);
            
        while(fast!=1 && fast!=slow ){
            slow = rec(slow);
            fast = rec(rec(fast));
        }
            
        return fast==1;
            
            
            
    }
    
    
    int rec(int n){
       
        int sum=0;
        while(n>0){
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
    
};
