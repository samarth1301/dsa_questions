class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //O(N^2)
        // int m = -999999999;
        // for(int i =0;i<points.size()-1;i++){
        //     for(int j=i+1;j<points.size();j++){
        //         if(points[j][0]-points[i][0]<=k){
        //             m = max(m,(points[j][1]+points[i][1]+(points[j][0]-points[i][0])));
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return m;
        
        
        //optimised solution
        //O(Nln(N))
        //maintain a priority queue for each value to the left side of our present iterated value
        // the priority queue will contain a pair of int,
        // one value is yi-xi which needs to be added into our present iterated value,
   
        //the value will be maintained using this sum value,
        //the second value will consist the x coordinate as we also need to check for the condition
        
        priority_queue <pair<int,int>> pq;
        int n = points.size();
        //this is ur result variable
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
          //remove all the previous elements from the pq which doest not meet the required condition, as the array was sorted, if this element 
          //does not meet the requirement, the next element wont meet the requirement too.
            while((!pq.empty()) && (points[i][0]-pq.top().second >k)) pq.pop();
            if(!pq.empty())
                ans = max(ans,points[i][0]+points[i][1]+pq.top().first);
            pq.push({points[i][1]- points[i][0], points[i][0]});
        }
        
        
        return ans;
        
        
        
        
        
        
    }
};
