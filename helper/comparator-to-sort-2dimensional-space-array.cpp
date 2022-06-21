class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]==b[0] && a[1]<b[1]){
            return true;
        }
        return false;
       
    }
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        for(auto i : points){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};
