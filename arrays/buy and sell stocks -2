//my approach
//sell and buy on the day when new minimum value is found or greater diff is found 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 9999999, maxdiff = 0,n=prices.size(),sum=0;
        for(int i=0;i<n;i++){
            if(min>prices[i]){
                min=prices[i];
                sum+=maxdiff;
                maxdiff=0;
            }
            if(maxdiff<prices[i]-min){
                maxdiff= prices[i]-min;
                
                sum+=maxdiff;
                maxdiff=0;
                min=prices[i];
            }
        }
        sum+=maxdiff;
        return sum;
    }
};

//or 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            
            
           
           
            if(prices[i+1]>prices[i]){
                        diff+=prices[i+1]-prices[i];
            }

        }
        return diff;
    }
};
