class Solution {
public:
    int characterReplacement(string s, int k) {
     

        int mx=0;
        unordered_set<char> st;
        //store elements in set
        for(auto c : s){
            st.insert(c);
        }


        //iterate each unique element
        // and check for the longest possible subarray

        for(auto itr: st){
            int st=0;
            int c =0;
            for(int end=0;end<s.size();end++){
                if(itr==s[end]){
                    c++;
                }
                while((end+1-st-c>k)){
                    if(s[st]==itr){
                        c--;
                    }
                    st++;
                }
                mx = max(mx,end+1-st);
            }
            // cout<<itr<<endl;
        }

        return mx;
    }
};
