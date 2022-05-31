
//using extra space

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp(board.begin(), board.end());
        int n=board.size(), m = board[0].size();
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count=0;
              
                  if((i-1)>=0){
                      if((j-1)>=0 && board[i-1][j-1]==1){
                          count++;
                      }
                      if(board[i-1][j]==1){
                          count++;
                      }
                       if((j+1)<m && board[i-1][j+1]==1){
                          count++;
                      }
                  }
                  if((j-1)>=0 && board[i][j-1]==1){
                      count++;
                  }
                  if((j+1)<m && board[i][j+1]==1){
                      count++;
                  }
                   if((i+1)<n){
                        if((j-1)>=0 && board[i+1][j-1]==1){
                          count++;
                      }
                      if(board[i+1][j]==1){
                          count++;
                      }
                       if((j+1)<m && board[i+1][j+1]==1){
                          count++;
                      }
                   }
                
                
                if(board[i][j]==1){
                    if(count<2){
                        temp[i][j]=0;
                    }
                    if(count==2 || count==3){
                        temp[i][j]=1;
                    }
                    if(count>3){
                        temp[i][j]=0;
                    }
                }
                if(board[i][j]==0 && count==3){
                    temp[i][j]=1;
                }
                
            }
           
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=temp[i][j];
            }
           
        }
    }
};



//without using extra space but marking all new changed zeros(in case when element is one) as 2,
//and all new changed ones (in case when element is zero) to -1,
// as long as counting is done, then changing 2 to zero, and -1 to 1,

//while counting is done in a fashion where only if the neighbour element is greater than or equal to one,
//we will increment the count, else not.
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                if(i>0 && board[i-1][j]>=1) c++;
                  if(i>0 && j>0 && board[i-1][j-1]>=1) c++;
                if(i>0 && j+1<m && board[i-1][j+1]>=1) c++;
                if(j>0 && board[i][j-1]>=1) c++;
                 if(j+1<m && board[i][j+1]>=1) c++;
                if(i+1<n && board[i+1][j]>=1) c++;
                  if(i+1<n && j>0 && board[i+1][j-1]>=1) c++;
                if(i+1<n && j+1<m && board[i+1][j+1]>=1) c++;
                cout<<c<<endl;
                if(board[i][j]==1 && (c<2 || c>3)){
                    board[i][j]=2;
                }
                else if(board[i][j]==0 && c==3){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1){
                    board[i][j]=1;
                }
                if(board[i][j]==2){
                    board[i][j]=0;

                }
            }
        }
    }
};
