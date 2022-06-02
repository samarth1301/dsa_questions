//question link : https://leetcode.com/problems/largest-rectangle-in-histogram/
//video link : https://www.youtube.com/watch?v=vcv3REtIvEo



//O(n^2) is tle
//O(N) solution discussed
//left array consists of left limits for each value
//right array consists of right limits for each value
//these values are derived with the use of a stack storing indices of all elements greater than the present element
//if a element less than the present element is found, stop the traversal and store in left or right array (stack.top+1 -> left) or (stack.top-1 ->right)
// then just find the max area with the help of area = (heights[i]*(right[i]-left[i]+1)
//heights[i] is the heights of the element and left and right are the limits to which it can traverse.




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=  heights.size();

        vector<int> left(n), right(n);
        stack<int> s;
        
        for(int i=0;i<n ; i++ ){
           
            while(!s.empty() && heights[i]<= heights[s.top()] ){
                s.pop(); 
            }
             if(s.size()==0){
                left[i]=(0);
                //s.push(i);
            }
            if(!s.empty()){
                left[i]=(s.top()+1);
            }
            
            s.push(i);
            
        }
        while(!s.empty()){
            s.pop();
        }
        
        
        for(int i=n-1;i>=0;i--){
              while(!s.empty() && heights[i]<= heights[s.top()] ){
                s.pop(); 
            }
             if(s.size()==0){
                right[i]=(n-1);
                //s.push(i);
            }
            if(!s.empty()){
                right[i]=(s.top()-1);
            }
            
            s.push(i);
        }
        
        int a=0;
        
        for(int i=0;i<n;i++){
            a = max(a,(heights[i]*(right[i]-left[i]+1)));
        }
        
        
        return a;
    }
};
