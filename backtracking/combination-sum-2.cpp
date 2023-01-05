class Solution {
public:
    vector<vector<int>> res;
    void recur(vector<int>& candidates, int target, int i,vector<int>& helper){
        if(target==0){
            res.push_back(helper);
            return;
        }
        if(i>=candidates.size()) return;
        if(target<0) return;
        // recur(candidates,target,i+1,helper);
        for(int k=i;k<candidates.size();k++){
            if(k>i && candidates[k]==candidates[k-1]) continue;tg
             helper.push_back(candidates[k]);
            recur(candidates,target-candidates[k],k+1,helper);
            helper.pop_back();
        }

       
        // int s = accumulate(helper.begin(),helper.end(),0);
        // if(s+candidates[i]==target){
        //     helper.push_back(candidates[i]);
        //     if(find(res.begin(),res.end(),helper)==res.end()) res.push_back(helper);
        //     helper.pop_back();
        //     return;
        // }
        // if(s+candidates[i]>target) return;
        // else{
        //     helper.push_back(candidates[i]);
        //     recur(candidates,target,i+1,helper);
        //     helper.pop_back();
        //     recur(candidates,target,i+1,helper);
        // }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> helper;
        sort(candidates.begin(),candidates.end());
        recur(candidates,target,0,helper);
        return res;
    }
};
