class Solution {
public:
    string convertToTitle(int n) {
        vector<char> arr = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        string s;
        //as long as number is greater than 0
        while(n>0){
            //numbers are in form 1,2,3
            //but modulo wil be 0,1,2,3
            n--;
            //add the modulo in the string
            //but this will be added in reverse order
            //so reverse it later
            s+=arr[n%26];
            //once you added the char in the string 
            //divide the number with 26
            n/=26;
        }      
       
        reverse(s.begin(),s.end());
        return s;
    }
};
