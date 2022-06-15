//quesiton : https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    //this is a very simple recursive helper function
    void fillFlood(vector<vector<char>>& mat,int x, int y, char prev, char newC){
        // if index x and y overshoot the matrix, go back
        if(x<0 || x>(mat.size())-1 || y<0 || y>(mat[0].size())-1)
            return;
        
        //if the present element being traversed is not previous element
        //in our case it is -(prev) than we will go back
        //because we are just convertin all -(prev) to 
        //O(newC) only if they are connected 
        
        if(mat[x][y]!=prev)
            return;
        
        //this is the condition when are present element is -
        // then we will convert this element to O
        
        mat[x][y]=newC;
        
        //and call this function again in the neighbour elements
        //i.e top bottom left right of  the present element
        fillFlood(mat,x+1,y,prev,newC);
        fillFlood(mat,x-1,y,prev,newC);
        fillFlood(mat,x,y+1,prev,newC);
        fillFlood(mat,x,y-1,prev,newC);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        //change each O to - 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                     mat[i][j]= '-';
                }
               
            }
        }
        
        //now traverse each edge and call fillFlood for each 
        //element equal to - in each edge
        // this fillFlood function will traverse each element which is equal to -
        // recursively and change it to O
        
        
        //top
        for(int i=0;i<m;i++){
            if(mat[0][i]=='-'){
                fillFlood(mat,0,i,'-','O');
            }
        }
        //right side
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='-'){
                fillFlood(mat,i,m-1,'-','O');
            }
        }
        //bottom
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='-'){
                fillFlood(mat,n-1,i,'-','O');
            }
        }
        //left
        for(int i=0;i<n;i++){
            if(mat[i][0]=='-'){
                fillFlood(mat,i,0,'-','O');
            }
        }
        
        //after traversal for each edge 
        //all the elemetns which are still - can be converted back to 
        //X
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='-'){
                     mat[i][j]= 'X';
                }
               
            }
        }
        return mat;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends
