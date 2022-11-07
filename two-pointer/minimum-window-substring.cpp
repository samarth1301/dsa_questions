class Solution {
public:
    string minWindow(string str, string pat) {
           
    // int len1 = str.length();
    // int len2 = pat.length();
        
    //  const int no_of_chars = 256;

    // if (len1 < len2) {
    //     return "";
    // }

    // int hash_pat[no_of_chars] = { 0 };
    // int hash_str[no_of_chars] = { 0 };

    
    // for (int i = 0; i < len2; i++)
    //     hash_pat[pat[i]]++;

    // int start = 0, start_index = -1, min_len = INT_MAX;

   
    // int count = 0; 
    // for (int j = 0; j < len1; j++) {
      
        
    //     hash_str[str[j]]++;

        
    //     if (hash_str[str[j]] <= hash_pat[str[j]])
    //         count++;

    //     if (count == len2) {
          
    //         while (hash_str[str[start]]
    //                    > hash_pat[str[start]]
    //                || hash_pat[str[start]] == 0) {

    //             if (hash_str[str[start]]
    //                 > hash_pat[str[start]])
    //                 hash_str[str[start]]--;
    //             start++;
    //         }

    //         int len_window = j - start + 1;
    //         if (min_len > len_window) {
    //             min_len = len_window;
    //             start_index = start;
    //         }
    //     }
    // }


    // if (start_index == -1) {
     
    //     return "";
    // }

    
    // return str.substr(start_index, min_len);
    if(str.size()<pat.size()) return "";
   
    int mn=INT_MAX , start = 0,st_idx=-1;
    unordered_map<char,int> hmap;
    for(auto c: pat) hmap[c]++;
    // bool cmpt = false;
    int c =0;
    unordered_map<char,int> hmap2;
    for(int i=0 ;i<str.size();i++){
            hmap2[str[i]]++;
            if(hmap[str[i]]>=hmap2[str[i]]){
                c++;
            }       
          if(c==pat.size()){
              while(hmap[str[start]]<hmap2[str[start]] || hmap[str[start]]==0){
                  if(hmap[str[start]]<hmap2[str[start]]) hmap2[str[start]]--;
                  start++;
              }
            //  while (hmap2[str[start]]
            //            > hmap[str[start]] || hmap[str[start]] == 0) {

            //     if (hmap2[str[start]]
            //         > hmap[str[start]])
            //         hmap2[str[start]]--;
            //     start++;
            // }
                int temp = i - start + 1;
                if(mn>temp){
              cout<<str[start]<<endl;

                    mn = temp;
                    st_idx = start;
                }
          }
         
    }
        if(st_idx==-1) return "";
        return str.substr(st_idx,mn);
    }
};
