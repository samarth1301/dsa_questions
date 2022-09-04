class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ns = s.size(), na= words.size(),c=0;
//         unordered_map<string,int> hmap;
//         for(int i =0 ; i<na ; i++){
//             hmap[words[i]]++;
//         }
//         // for(int i=0;i<na;i++){
//         //     int indx = 0;
//         //     for(int j = 0;j<ns;j++){
//         //         if(words[i][indx]==s[j]){
//         //             indx++;
//         //         }
//         //         if(indx>=words[i].size()) {
//         //             c++;
//         //             break;
//         //         }
//         //     }
//         // }
       
//         for(auto it :hmap){
//             if(check(s,it.first)){
//                 c+=it.second;
//             }
//         }
//         return c;
//     }
//     bool check(string s, string f){
//         int i=0,j=0;
//         while(j!=f.size()){
//             if(i==s.size()) return false;
//             if(s[i]==f[j]){
//                 i++;
//                 j++;
//             }
//             else{
//                 i++;
//             }
//         }
//         return true;
        //store each string on the basis of initials
        unordered_map<char,vector<string>> hmap;
        for(int i =0 ;i< na ; i++){
            hmap[words[i][0]].push_back(words[i]);
        }
        //for each char in s string
        for(int  i =0 ;i<s.size();i++){
            //store all the strings in a temp array 
            vector<string> arr;
            for(auto itr = hmap[s[i]].begin(); itr != hmap[s[i]].end();itr++){
                string temp = *itr;
                
                arr.push_back(temp);
              
            }
            //clear the array in map
            hmap[s[i]].clear();
            //use the temp array to fill all the values again 
            //skipping the first value
            for(int i =0 ; i < arr.size();i++){
                string temp = arr[i];
                temp = temp.substr(1);
                if(temp.size()==0){
                    c++;
                    continue;
                }
                hmap[temp[0]].push_back(temp);
            }
        }
        return c;
    }
};
