class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        // unordered_map<string,unordered_map<char,int>> mp;
        // for(auto s: words){
        //     unordered_map<char,int> temp;
        //     for(auto c: s){
        //         temp[c]++;
        //     }
        //     mp[s] = temp;
        // }
        // //  for(auto s: mp){
        // //     // unordered_map<char,int> temp;
        // //      cout<<s.first<<endl;
        // //     for(auto c: s.second){
        // //         cout<<c.first<<" : "<<c.second<<endl; 
        // //     }
        // //     // mp[s] = temp;
        // // }
        // for(int i =0;i<words.size();i++){
        //     for(int j=0;j<words.size();j++){
        //         // unordered_map<char,int> temp;
        //         // for(auto c: mp[words[i]]){
        //         //     temp[c.first]+= c.second;
        //         // }
        //         // for(auto c: mp[words[j]]){
        //         //     temp[c.first]+= c.second;
        //         // }
        //         // bool once = false;
        //         // int c =0;
        //         // for(auto t:temp){
        //         //     if(once) break;
        //         //     if(t.second%2==1){
        //         //         once = true;
        //         //     }
        //         //     c++;
        //         // }
        //         if( i!=j && check(words[i]+words[j])){
        //             res.push_back({i,j});
        //         }
        //     }
        // }
        // return res;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            mp[temp] = i;
        }
        
        
        if(mp.find("")!=mp.end()){
            for(int i =0;i<words.size();i++){
                if(words[i]=="") continue;
                if(check(words[i])){
                    res.push_back({mp[""],i});
                }
            }
        }
        for(int i =0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                auto left = words[i].substr(0,j);
                auto right = words[i].substr(j,words[i].size()-j);
                if(mp.find(left)!=mp.end() && check(right) && mp[left]!=i){
                    res.push_back({i,mp[left]});
                }
                if(mp.find(right)!=mp.end() && check(left) && mp[right]!=i){
                    res.push_back({mp[right],i});
                }
            }
        }
       
        return res;
    }
    bool check(string s){
        int i =0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
       
    }
};
