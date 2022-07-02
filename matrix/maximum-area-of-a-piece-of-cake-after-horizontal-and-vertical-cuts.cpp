class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long int maxL=INT_MIN;
        const unsigned int m = 1000000007; 
        for(int i=0; i<horizontalCuts.size();i++){
            long long int temp =0;
            if(i==0){
                temp=horizontalCuts[i];
            }
            // else if(i==horizontalCuts.size()-1){
            //     temp=horizontalCuts[i];
            // }
            else{
                temp= horizontalCuts[i]-horizontalCuts[i-1];
            }
            
            maxL = max(maxL,temp);
        }
        maxL = max(maxL,(long long int) h-horizontalCuts[horizontalCuts.size()-1]);
         long long int maxW=INT_MIN;
        for(int i=0; i<verticalCuts.size();i++){
            long long int temp =0;
            if(i==0){
                temp=verticalCuts[i];
            }
            // else if(i==horizontalCuts.size()-1){
            //     temp=horizontalCuts[i];
            // }
            else{
                temp= verticalCuts[i]-verticalCuts[i-1];
            }
            
            maxW = max(maxW,temp);
        }
        maxW = max(maxW, (long long int)w-verticalCuts[verticalCuts.size()-1]);
        maxL %= m;
        maxW %= m;
        return (maxW*maxL)%m;

    }
};
