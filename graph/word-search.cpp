class Solution {
public:
    
    bool recur(vector<vector<char>>& board, string word,int i, int j , int k){
        int m = board.size(),n = board[0].size();

        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k]) return false;
        if(k+1==word.size()) return true;
        
        board[i][j] = '-';
        
        bool res =  (recur(board,word,i+1,j,k+1) || recur(board,word,i-1,j,k+1) || recur(board,word,i,j-1,k+1) || recur(board,word,i,j+1,k+1));
        board[i][j] = word[k];
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size();
        for(int i = 0 ;i<m ; i++){
            for(int  j = 0 ; j< n ; j++){
                if(board[i][j]==word[0] && recur(board,word,i,j,0)){
                            return true;
                }
            }
        }
    return false;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]==word[0]){
//                     int count=1;
//                     int a=i,b=j,prevb= b-1;
//                     int indx=1;
//                     multimap<int,int> hmap;
//                     hmap.insert({i,j});
//                     //hmap[i]=j;
//                     while(count!=word.size()){
//                         if(b+1<n && word[indx]==board[a][b+1]  ){
//                             indx++;
//                             prevb=b;
//                             b++;
//                             count++;
                          
//                         }
//                         else if (b-1>=0 && word[indx]==board[a][b-1] && b-1!=prevb  ){
//                             indx++;
//                             prevb=b;
//                             b--;
//                             count++;
                          
//                         }
//                         else if(a+1<m && word[indx]==board[a+1][b] ){
//                             indx++;
//                             a++;
//                             count++;
                           
//                         }
//                         else if (a-1>=0 && word[indx]==board[a-1][b] ){
//                             indx++;
//                             a--;
//                             count++; hmap[a-1]=b;
//                         }
//                         else{
//                             break;
//                         }
//                     }
//                     if(count==word.size()){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
    }
};
