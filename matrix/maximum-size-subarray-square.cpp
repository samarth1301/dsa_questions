
#include <bits/stdc++.h>
#include <iostream>
// #include<vector>
using namespace std;
//dp fro maximum square size matrix

void printMaxSubSquare(bool arr[6][5]){
    int r=6,c=5;
    vector<vector<int>> temp(r,vector<int>(c,0));
    // copy first row and first column as it is
    for(int i =0 ;i<5;i++){
        temp[0][i]=arr[0][i];
    }
    for(int i =0 ;i<6;i++){
        temp[i][0]=arr[i][0];
    }
    
    //if element is 1, check for the minimum number around it 
    //and add 1 to it cause present element is 1
    //if 0, just give the value as zero
    for(int i=1;i<6;i++){
        for(int j=1;j<5;j++){
            if(arr[i][j]==1){
                temp[i][j]= min({temp[i][j-1],temp[i-1][j],temp[i-1][j-1]}) + 1;
            }
            else{
                temp[i][j]=0;
            }
        }
    }    
   
     //calculate max number in temp
     //and store its i and j index
    
    int max=INT_MIN,max_i,max_j;
    
     for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
            if(max<temp[i][j]){
                max= temp[i][j];
                max_i=i;
                max_j=j;
            }
            
        }
    }    
    
    //now just print or return a 2d array with dimension
    //(max_i-(max-1) to max_i) * (max_j-(max-1) to max_j)
    
    for(int i=max_i;i>=(max_i-(max-1));i--){
        for(int j=max_j;j>=(max_j-(max-1));j--){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    bool M[6][5] = {{0, 1, 1, 0, 1},
                    {1, 1, 1, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
    return 0;
}
