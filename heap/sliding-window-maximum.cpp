class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> res;
        if(k==0) return res;
        priority_queue<pair<int,int>> pq;
      //heap storing value and index
        for(int  i =0 ; i < n;i++){
          //if top value's index is less than present windows start index
          //pop out the value
            while(!pq.empty() && pq.top().second<=i-k) pq.pop();
          //push each value in the pq.  
          pq.push({nums[i],i});
          //if you have visited k indices, start adding max value into the result vector
            if(i>=k-1) res.push_back(pq.top().first);
        }
        return res;
    }
};
