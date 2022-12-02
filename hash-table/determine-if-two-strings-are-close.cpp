class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // unordered_map<int,int> hmap,hmap2;
        // if(word1.size()!=word2.size()) return false;
        // for(auto c : word1){
        //     hmap[c]++;
        // }
        // for(auto c : word2){
        //     hmap2[c]++;
        // }
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(auto c:word1) arr1[c-'a']++;
        for(auto c:word2) arr2[c-'a']++;
        for(int i=0;i<26;i++){
            if(arr1[i]==0 && arr2[i]==0) continue;
            if(arr1[i]==0 || arr2[i]==0) return false;
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        for(auto i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;

    }
};
