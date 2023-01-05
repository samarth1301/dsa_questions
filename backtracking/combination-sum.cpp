class Solution {
public:
        vector<vector<int>> res;

    void recur(vector<int> & arr, int i,vector<int> & temp, int t){
        if(i>=arr.size()) return;
        if(t<0) return;
        if(t==0){
            res.push_back(temp);
            return;
        }

        //skipping current value;
        recur(arr,i+1,temp,t);

        //using current value;
        temp.push_back(arr[i]);
        recur(arr,i,temp,t-arr[i]);
        temp.pop_back();

       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> temp;
            recur(candidates,0,temp,target);
            return res;
    }
};
