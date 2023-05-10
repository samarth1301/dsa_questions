class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    //array to store the new matrix
        vector<vector<int>> arr(n, vector<int> (n,0));
        //position of each pointer
        int top = 0, left = 0, right = n-1, bottom = n-1;
        //dir to decide in what direction the traversal will be done
        int dir = 1, ele = 1;
        while(top<=bottom && left<=right){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    arr[top][i] = ele++;
                }
                //after the traversal, move the top pointer to the next row
                top++;
                dir=2;
            }
            else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    arr[i][right] = ele++;
                }
                right--;
                dir = 3;
            }
            else if(dir==3){
                for(int i=right;i>=left;i--){
                    arr[bottom][i] = ele++;
                }
                bottom--;
                dir = 4;
            }
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    arr[i][left] = ele++;
                }
                left++;
                dir = 1;
            }
        }
        return arr;
    }
};
