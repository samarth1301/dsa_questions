class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> hmap;
        for(auto s : words){
            hmap[s]++;
        }
        int  cnt=0;
        bool mid = false;
        for(auto[s,c]:hmap){
            string temp = {s[1],s[0]};
            if(s[0]==s[1]){
               if(c%2==0){
                   cnt+=c;
               }
               else{
                   cnt+=c-1;
                   mid = true;
               }
            }
            // cout<<s[0]+s[1]<<endl;
            else if(s[0]<s[1] && hmap.count(temp)){
                cnt += 2*(min(c,hmap[{s[1],s[0]}]));
            }
        }
        if(mid) cnt++;
        return 2*cnt;
    }
};
