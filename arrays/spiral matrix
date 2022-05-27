class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m= matrix.size(),n = matrix[0].size(), upper= 0, lower = m-1, right = n-1, left=0;
        vector<int> arr;    
    
        
        //another condition for while loop could have been total = m*n , decrementing total 
        //each time we visit one element, when total becomes 0, we come out of the loop, 
        //using if condition after each forloop and while(total); 
        while(upper<=lower && left<=right ){
            for(int i=left;i<=right;i++){
                arr.push_back(matrix[upper][i]);
            }
            upper++;
            for(int i=upper;i<=lower;i++){
                //cout<<"upper se lower"<<endl;
                arr.push_back(matrix[i][right]);
            }
            right--;
            cout<<"left :"<<left<<" right:"<<right<<" top:"<<upper<<" bottom:"<<lower<<endl;
            if(left>right || upper > lower){
                continue;
            }
            for(int i=right;i>=left;i--){
                arr.push_back(matrix[lower][i]);
            }
            lower--;
            for(int i=lower;i>=upper;i--){
                arr.push_back(matrix[i][left]);
            }
            left++;
            
        }
       //arr.push_back(matrix[m/2][n/2]);
        return arr;
    }
};
