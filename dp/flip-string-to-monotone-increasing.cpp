class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c0 = 0;
        for(auto c : s){
            if(c=='0') c0++;
        }
        int mn = c0;

        for(auto c:s){
            if(c=='0'){
                c0--;
            }
            else{
                c0++;
            }
            mn = min(mn, c0);
        }
        return mn;













        // int ans =0;
        // for(auto c : s){
        //     if(c=='0') ans++;
        // }
        // int mn = ans;
        // for(auto c : s){
        //     if(c=='0'){
        //         mn = min(mn,--ans);
        //     }else{
        //         ans++;
        //     }
        // }
        // return mn;
        
    }
};
