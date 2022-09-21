class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto i : nums){
            if(i%2==0){
                sum+=i;
            }
        }
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            auto temp = nums[queries[i][1]];
            if(temp%2==0) sum-=nums[queries[i][1]];
            nums[queries[i][1]]+=queries[i][0];
            if(nums[queries[i][1]]%2==0) sum+=nums[queries[i][1]];
            res.push_back(sum);
        }
        return res;
    }
};
