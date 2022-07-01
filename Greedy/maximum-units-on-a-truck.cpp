//question link - https://leetcode.com/problems/maximum-units-on-a-truck/
//sort in ascending order of value and keep selecting each value till you overshoot truck size
class Solution {
public:
    static bool comp(vector<int> a,vector<int>b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int limit = truckSize,res=0;
        // for(int i=0;i<n;i++){
        //     cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
        // }
        int i=0;
        while(limit > 0){
            if(i==n){
                break;
            }
            if(limit>boxTypes[i][0]){
                limit-=boxTypes[i][0];
                res+=boxTypes[i][1]*boxTypes[i][0];
            }
            else{
                int temp = limit;
                limit =0;
                res+=boxTypes[i][1]*temp;
            }          
            i++;
        }
        return res;
    }
};
