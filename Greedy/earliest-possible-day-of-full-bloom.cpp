class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<growTime.size();i++){
            // double r = (double)growTime[i]/plantTime[i];
            double r = (double)growTime[i];

            pq.push({r,i});
        }
        int result = 0,sum=0;
        while(!pq.empty()){
            auto temp = pq.top();
            // cout<<temp.first<<" : "<<temp.second<<endl;
            pq.pop();
            sum+= plantTime[temp.second];
            result = max(result,sum + growTime[temp.second]);
        }
        return result;
    }
};
