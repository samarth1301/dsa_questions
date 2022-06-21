class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        //max vairiable to store the max points on the same line
        int max = INT_MIN;
        //in case you have only two or less than two elements in 2d
        //return that many elements, coz at minimum you can have two elements in same line
        //unless you have less than two points
        if(points.size()<=2) return points.size();
        //traverse each element till second last element.
        for(int i=0;i<points.size()-1;i++){
            //for each element, check how many slopes are similar for that iteration,
            //we have hmap here because, we are maintaing number of similar slopes 
            //for each iteration, and not for the entire 2d space,
            //for ex, for first element, we need to maintain similar slopes with that point
            //for second element, we will maintain another similar slopes collection
            
            //for each element, we will have all similar slopes of that and the next elements,
            //we are not declaring this hmap outside the forloop, as doing so,
            //will cause similar slopes of different elements to be stored in hmap, which will cause
            //disparency, we just need to keep in account similar slopes of one element at a moment.
            unordered_map<float,int> hmap;
            //iterate next elements and store their slope with this point
            for(int j=i+1;j<points.size();j++){
                float slope;//slope can be decimal value
                //in case x2-x1 == 0, slope will be infinity 
                if(float(points[j][0]-points[i][0])==0){
                    slope=INT_MAX;
                }
                //other-wise calculate your slope, we cant use abs here
                //as slope can be negative as well as positive,
                //but we need to typecast these values into float anyways, otherwise they would come up
                //as int
                else{
                     slope = (float(points[j][1]-points[i][1]))/(float(points[j][0]-points[i][0]));
                }
                //store your slope in hmap, similar slopes count is maintained here
                hmap[slope]++;
                
                //in case your similar slope count is greater than max, store the max value
                if(hmap[slope]>max){
                    max=hmap[slope];
                }
            }
          
        }
       
       //here we are returning 1+max, why?
        //because max is the value of max similar slopes between n elements
        //if n==3, then we will have three points say x1,x2,x3
        //then max similar slopes will be ?
        //x1-x2,x1-x3, for iteration x1, we are not calcualting x2-x3 here
        //thus for n points in a line, we will have n-1 similar slopes in one iteration
        
        return max+1;
    }
};
