class Solution {
public:
  
  //simple if else binary addition using one carry -_-
  //keep adding answer in res string at the end and then reverse at the end
  //as insert is O(N) and reverse is also O(N)
  //but it will be better if we use reverse only once
    string addBinary(string a, string b) {
        int c=0;
        int i=a.size()-1,j=b.size()-1;
        string res="";
      //this loop works as long as there is one element in both the strings
        while(i>=0 && j>=0){
            // cout<<i<<" "<<j<<endl;
            if(c==0){
                if(a[i]=='1' && b[j]=='1'){
                    c=1;
                    res+=('0');
                }
                if((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1')){
                    c=0;
                    res+=('1');
                }
                if(a[i]=='0' && b[j]=='0'){
                    c=0;
                    res+=('0');
                }
            }
            else if(c==1){
                if(a[i]=='1' && b[j]=='1'){
                    c=1;
                    res+=('1');
                }
                if((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1')){
                    c=1;
                    res+=('0');
                }
                if(a[i]=='0' && b[j]=='0'){
                    c=0;
                    res+=('1');
                }
            }
            i--;
            j--;
        }
      //this loop works when b is exhausted 
        while(i>=0){
            if(c==0){
                res+=(a[i]);
            }
            else if(c==1){
                if(a[i]=='0'){
                    c=0;
                    res+=('1');
                }
                if(a[i]=='1'){
                    c=1;
                    res+=('0');
                }
            }
            i--;
        }
      //this loop runs when a is exhausted
         while(j>=0){
            if(c==0){
                res+=(b[j]);
            }
            else if(c==1){
                if(b[j]=='0'){
                    c=0;
                    res+=('1');
                }
                if(b[j]=='1'){
                    c=1;
                    res+=('0');
                }
            }
             j--;
        }
        
        if(c==1){
            res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
