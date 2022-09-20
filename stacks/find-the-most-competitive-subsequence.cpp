class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.back()>nums[i] && st.size()-1+nums.size()-i>=k){
                st.pop_back();
            }
            if(st.size()<k){
                st.push_back(nums[i]);
            }
        }
        return st;
    }
};
