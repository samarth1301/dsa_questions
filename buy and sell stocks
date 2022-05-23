class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 999999,n= prices.size(),maxdiff=0;
        for(int i=0;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
                // maxdiff=0;
            }
            if(maxdiff<prices[i]-min){
                maxdiff=prices[i]-min;
            }
        }
        return maxdiff;
    }
};
