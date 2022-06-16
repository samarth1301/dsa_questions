class Solution{
  public:
  int maxArea(int arr[],int size){
      vector<int>left(size),right(size);
      stack<int> stck;
      
    
    //calculate left and right here
      for(int i=0;i<size;i++){
       
        while(!stck.empty() && arr[stck.top()]>= arr[i]){
            stck.pop();
        }
        if(stck.empty()){
            left[i]=0;
        }
        else{
            left[i]=stck.top()+1;
        }
          stck.push(i);
        
      }
     
      
      while(!stck.empty()){
          stck.pop();
      }
      
      for(int i=size-1;i>=0;i--){
         
          while(!stck.empty() && arr[stck.top()]>=arr[i]) {
              stck.pop();
          }
          if(stck.empty()){
              right[i]=size-1;
          }
          else{
              right[i]=stck.top()-1;
          }
          stck.push(i);
      }
     
      
      
      int area = INT_MIN;
      
      for(int i=0;i<size;i++){
          area = max(area, arr[i] * (right[i]-left[i]+1));
      }
     
      return area;
      
      
  }
  //here we use maximum rectanble in histogram as a helper function for each row
  //we will calculate largest rectangle in each row
  //and if the current row is not the first row
  //we add all the above values (1's) to the preesent row's element
  //but if current element is zero we leave it as it is
  //and calculate largest rectangle in each row
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = maxArea(M[0],m);
       
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]){
                    M[i][j]+=M[i-1][j];    
                }
               
            }
          
            res = max(res,maxArea(M[i],m));
        }
        return res;
    }
};
