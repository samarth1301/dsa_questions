class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double mn = INT_MAX;
        //TLE
        // for(int i=0;i<quality.size();i++){
        //     double ratio =double(wage[i])/ double(quality[i]);
        //    vector<double> res;
        //     res.push_back(wage[i]);
        //     for(int j=0;j<quality.size();j++){
        //         if(i!=j){
        //             double temp =(double) quality[j]*ratio;
        //             // cout<<temp<<endl;
        //             if(temp>=wage[j]){
        //                 res.push_back(temp);
        //             }
        //         }
        //     }
        //     if(k>res.size()) continue;
        //     sort(res.begin(),res.end());
        //    double sum =0;
        //     for(int i=0;i<k;i++){
        //         sum+=res[i];
        //     }
        //     mn = min(mn,sum);
        // }
        // return mn;
        vector<vector<double>> arr;
        for(int i =0;i<wage.size();i++){
            arr.push_back({(double)(wage[i])/quality[i],(double)quality[i]});
        }
        sort(arr.begin(),arr.end());
        double sum=0;
        double res = INT_MAX;
        priority_queue<int> pq;
          for(int i =0;i<arr.size();i++){
              sum+=arr[i][1];
              pq.push(arr[i][1]);
              // cout<<pq.size()<<" "<<k<<endl;
              if(pq.size()>k){
                   sum-=pq.top();pq.pop();
              }
                 
              if(pq.size()==k) res =  min(res,sum*arr[i][0]);
              // cout<<pq.size()<<endl;
          }
        return res;
    }
};
