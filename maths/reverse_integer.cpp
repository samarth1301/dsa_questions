class Solution {
public:
    int reverse(int x) {
        //my approach
        
        //check if number is negative or positive
        int neg =1;//if positive
        if(x<0){
            neg = -1; //if negative
        }
        
        //if 0 return zero
        if(x==0){
            return 0;
        }
        //remove all trailing zeroes at right
        while(x%10==0){
            x/=10;
        }
        //reversed number
        int num= 0;
        //if original number is negative
        // convert it into positive but check for overflow first
        if(neg==-1){
            //if x is less than minimum possible integer
            //once we convert it into positive
            //it'll overflow 
            if(x<=INT_MIN){
                return 0;
            }
            x*=-1;
        }
        
        //traverse each number from right and add it into resulting number
        while(x>0){
            //lets check for overflow first
            //we are multiplying  10 into num
            //so num must be less than INT_MAX/10 so it wont overflow
            //if num > INT_MAX/10, there will be overflow
            //so return 0.
            if(num>INT_MAX/10 || (num==INT_MAX/10 && (x%10>7))){
                return 0;
            }
            //else keep adding each number from right into our new number
            num = num*10 + (x%10);
            x/=10;
        }
        //if number was negative, return negative number
        //else return number as it is
        return neg<0 ? -1 * num : num; 
    }
};
