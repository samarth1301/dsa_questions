class Solution {
public:
    string removeDuplicates(string s, int k) {
//         stack<char> st;
//         int c = 1;
//         char last = '-';
//         for(int i = 0 ;i<s.size();i++){
//              st.push(s[i]);
//             if(s[i]!=last){
//                 c = 1;
//                 last = s[i];
//             }
//             else{
//                 c++;
//             }
//             if(c==k){
//                 for(int i = 1; i<=k; i++){
//                     st.pop();
//                 }
//                 // c=1;
//                 int temp = 0;
//                 last = st.top();
//                 while(st.top()==temp){
//                     temp++;
//                     st.pop();
//                 }
//                 c=temp;
//                 while(temp){
//                     st.push(last);
//                     temp--;
//                 }
                
//             }
           
//         }
//         string res= "";
//         while(!st.empty()){
//             res+=st.top();
//             st.pop();
//         }
//         reverse(res.begin(),res.end());
//         return res;
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top().first==s[i]){
                st.top().second++;
            }
            else{
                st.push({s[i],1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string res ="";
        while(!st.empty()){
            for(int i=0;i<st.top().second;i++){
                res+=st.top().first;
            }
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
