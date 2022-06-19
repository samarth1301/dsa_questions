//question - https://leetcode.com/problems/power-of-two/submissions/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //if number is less than or equal to zero, it cant be power of +2
//         if(n<=0){
//             return false;
//         }
//         //store logarithimic decimal value in double for more precision
//         double temp = log2(n);
//         //we use floor to get the integer value 
//         int temp2 = floor(temp);
//         //subtract both and if there exists some decimal value, it means 
//         //the number is not power of 2.
//         // float res = temp-temp2;
//         // if(res>0){
//         //     return false;
//         // }
//         //____________ or __________________
// //         comparing int and float type, int becomes float with 0 decimals
//         if(temp!=temp2){
//             return false;
//         }
//         return true;
        
        
        
        
        
        
        
        
        
//         /////////////////////////////////////////////////////////////////
        //one more method using bit manipulation
        //for example 7->0111 and 8->1000 
        // using and operation this will always give zero
        //thus all elements which are divisible by 2 will always act the same way.
        if(n<=0)
            return false;
        return((n&(n-1))==0);
    }
};
