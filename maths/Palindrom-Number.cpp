class Solution {
public:
    bool isPalindrome(int x) {
        
        //my first approach
// ___________________________________________
        
//         if(x<0){
//             return false;
//         }
//         if(x==0)
//             return true;
//         vector<int> arr;
        
        
//         while(x>0){
//             int temp = x%10;
//             arr.push_back(temp);
//             x/=10;
//         }
        
//         vector<int> rev(arr.begin(),arr.end());
//         reverse(arr.begin(),arr.end());
        
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]!=rev[i]){
//                 return false;
//             }
//         }
//         return true;
        
//         ____________________________________________
        
        
//         more optimal solution
        //O(ln(n))
        
        
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        
        
        //take first half numbers and reverse them
        int rev = 0;
        
        
        //as long as rev is less than original number
        while( rev<x){
            //update rev by mulitplying with 10 and adding last digit of orignal number
            rev = rev*10+(x%10);
            //divide original number by 10.
            x/=10;
        }
        //then compare your original number with the reversed number
        return x==rev || x==rev/10;
        //even case       odd case
        
        
        
        
    }
};
