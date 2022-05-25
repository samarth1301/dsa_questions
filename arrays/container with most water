class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,n=height.size(),j=n-1,max=-1;
        while(i<j){
            int temp = min(height[i],height[j]);
            //cout<<"i: "<<i<<" j:"<<j<<endl;
            if(max<(j-i)*(temp)){
                max=(j-i)*(temp);
                //cout<<max<<endl;
            }
            if(height[i]<=height[j]){
                i++;
            }
            else if(height[i]>height[j]){
                j--;
            }
        }
        return max;
    }
};
